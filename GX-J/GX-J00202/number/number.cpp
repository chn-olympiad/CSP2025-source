#include <bits/stdc++.h>
using namespace std;
int  a[1000010];
int main()
{
    freopen("number.in,"r",stdin);
    freopen("number.out,"w",stdout);
    int x=1;
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            a[x]=s[i]-'0';
            x++;
        }
    }
    for (int i=1;i<=x;i++)
    {
        for (int j=1;j<=x;j++)
        {
            if (a[j]<a[j+1])
            {
                int n;
                n=a[j];
                a[j]=a[j+1];
                a[j+1]=n;
            }
        }
    }
    for (int i=1;i<=x-1;i++)
    {
        cout<<a[i];
    }
    return 0;
}
