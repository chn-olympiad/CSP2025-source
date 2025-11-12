#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<=n-1;i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            a[s[i]-'0']++;
        }

    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
