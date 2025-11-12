#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[11];
    memset(a,0,sizeof(a));
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        char c;
        c=s[i];
        if(isdigit(c))
        {
            a[c-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j = 0;j<a[i];j++)
            cout<<i;
    }
    return 0;
}
