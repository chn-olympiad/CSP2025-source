#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

long long n[100];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) n[s[i] - '0']++;
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
