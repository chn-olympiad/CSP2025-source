#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> a;
    for (char &i : s)
    {
        if (isdigit(i))
        {
            a.push_back(i - '0');
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int &i : a)
    {
        cout << i;
    }
}