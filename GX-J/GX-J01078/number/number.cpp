#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    string s;
    cin >> s;
    vector<int> a(10, 0);
    for(char c : s)
    {
        c -= '0';
        if(0 <= c && c <= 9)
            a[c]++;
    }
    for(int i = 9; i >= 0; i--)
    {
        while(a[i])
        {
            cout << i;
            a[i]--;
        }
    }
    return 0;
}
