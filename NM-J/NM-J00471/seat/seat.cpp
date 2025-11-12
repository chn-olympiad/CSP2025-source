#include <bits/stdc++.h>
using namespace std;
int s[999999];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c,d,e,f,n,m;
    cin >> n >> m;
    for (int i = 1;i<=n*m;i++)
    {
        cin >> s[i];
    }
    a=s[1];
    for (int i = 1;i<=n*m;i++)
    {
        for (int j = 1;j<=n*m;j++)
        {
            if (s[j]<s[j+1])
            {
                b=s[j];
                s[j]=s[j+1];
                s[j+1]=b;
            }
        }
    }
    for (int i = 1;i<=n*m;i++)
    {
        if (s[i]==a)
        {
            c=i+1;
        }
    }
    if (c%n==0)
        d=c/n;
    else
        d=c/n+1;
    e=c%n;
    if (d%2==1)
        f=e+1;
    else
        f=n-e;
    cout << f << " " << d;
}
