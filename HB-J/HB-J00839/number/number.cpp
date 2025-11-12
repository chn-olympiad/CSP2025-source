#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
vector<int> numbers;

bool cmp(const int& a, const int& b) {
    return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> str;

    for (char c : str) {
        if (isdigit(c))
            numbers.push_back((int)(c - '0'));
    }

    sort(numbers.begin(), numbers.end(), cmp);

    for (const int& num : numbers)
        cout << num;

    cout << "\n";
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}