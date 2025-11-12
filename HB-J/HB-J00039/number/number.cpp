#include <bits/stdc++.h>
using namespace std;
int a[1000005],ans[1000005],num[20];
int main()
{
    freopen(number.in,"r",stdin);
    freopen(number.out,"w",stdout);
    string s;
    cin >> s;
    int n=s.length()+1;
    for(int i=0;i<=n;i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            a[i+1]=s[i]-48;
        }
        else
        {
            a[i+1]=-1;
        }
    }
    int x=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0)
        {
            ans[x]=a[i];
            x++;
        }
    }
    for(int i=1;i<x;i++)
    {
        num[ans[i]]++;
    }
    for(int i=9;i>=0;i--)
    {
        if(num[i]>0)
        {
            for(int j=1;j<=num[i];j++)
            {
                cout << i;
            }
        }
    }
    return 0;
}
