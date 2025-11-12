#include <bits/stdc++.h>
using namespace std;

vector<int> num;
bool cmp(int x, int y) {return x > y;}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            num.push_back(c - '0');
        }
    }
    sort(num.begin(), num.end(), cmp);
    for (int x : num) {
        cout << x;
    }
    return 0;
}