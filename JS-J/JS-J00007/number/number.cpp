#include <bits/stdc++.h>
using namespace std;
int a[10] = {};
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (auto c : s)
    {
        if(isdigit(c))
        {
            int num = c - '0';
            a[num]++;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        while(a[i])
        {
            cout << i;
            a[i]--;
        }
    }
    return 0;
}
/*
g++ -Wall -O2 -std=c++14 -static number.cpp -o number
*/
