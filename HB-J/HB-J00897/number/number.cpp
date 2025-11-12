#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> numbers;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) numbers.push_back(s[i] - '0');
    }
    sort(numbers.begin(), numbers.end(), cmp);
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i];
    return 0;
}
