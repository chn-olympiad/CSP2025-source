#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
bool cnp(int a, int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    vector<int> vec;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            vec.push_back(s[i] - '0');
        }
    }
    sort(vec.begin(), vec.end(), cnp);
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i];
    }
}
