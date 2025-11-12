#include<bits/stdc++.h>
using namespace std;
//#define int long long

int tong[15];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int lens = s.length();
    for(int i = 0;i < lens;i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            tong[s[i] - '0']++;
        }
    }
    for(int i = 9;i >= 0;i--)
    {
        int tmp = tong[i];
        while(tmp--)
        {
            cout << i;
        }
    }
/*
    for(int i = 0;i <= 9;i++)
    {
        cout << tong[i] << " ";
    }
    */
    return 0;
}
