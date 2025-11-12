#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    int a[100005],tot=1,t,x;
    cin>>s;
    for (int i=0;i<=s.length();i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
            x=s[i]-'0';
            a[tot]=x;
            tot++;
        }

    }
    for (int i=1;i<tot-1;i++)
    {
        for (int j=i+1;j<=tot-1;j++)
        {
            if (a[i]<a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for (int i=1;i<tot;i++)
    {
        cout<<a[i];
    }

    return 0;
}
