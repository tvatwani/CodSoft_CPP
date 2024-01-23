#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "\nTodo List Program\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Remove Task\n";
    cout << "4. Mark Task as Complete/Incomplete\n";
    cout << "5. Exit\n";
}

void addTask(vector<Task> &tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        cout << "\nTask List:\n";
        cout << setw(5) << "ID" << setw(30) << "Description" << setw(15) << "Status\n";
        cout << "------------------------------------------\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << setw(5) << i + 1 << setw(30) << tasks[i].description << setw(15)
                 << (tasks[i].completed ? "Complete" : "Incomplete") << "\n";
        }
    }
}

void removeTask(vector<Task> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the task number to remove: ";
        size_t taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}

void markTask(vector<Task> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the task number to mark as complete/incomplete: ";
        size_t taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = !tasks[taskNumber - 1].completed;
            cout << "Task marked successfully.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}

int main() {
    vector<Task> tasks;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                removeTask(tasks);
                break;
            case 4:
                markTask(tasks);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
