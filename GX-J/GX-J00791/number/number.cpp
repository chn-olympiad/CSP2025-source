#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ans;
vector<int> a;
string s;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (isdigit(s[i])) {
            a.push_back(s[i] - '0');
        }
    }
    sort(a.begin(), a.end(), cmp);
    for (int i : a) {
        cout << i;
    }
    cout << "\n";
    return 0;
}
