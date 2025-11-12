#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str;
vector<int> arr;
bool cmp(int first, int second) {
    return first > second;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> str;
    for (char& i : str) {
        if ('0' <= i && i <= '9') {
            arr.push_back(i - '0');
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int& i : arr) {
        cout << i;
    }
    cout << endl;
    return 0;
}
