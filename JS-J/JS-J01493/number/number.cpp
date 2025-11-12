#include<bits/stdc++.h>
using namespace std;
int a[11];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if('0'<=s[i] && '9'>=s[i])
        {
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(a[i]>0)
        {
            cout << i;
            a[i]--;
        }
    }
    return 0;
}
