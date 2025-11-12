#include <bits/stdc++.h>
using namespace std;
long long n,m,i,d,a,b;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n*m;i++)
    {
        cin>>a;
        if (i==1)b=a;
        if (a>=b)
        {
            d++;
        }
    }
    if (d%n==0)m=d/n;
    else m=d/n+1;
    cout<<m<<' ';
    if (m%2==0)
    {
        if (d%n==0)cout<<1;
        else cout<<n-d%n+1;
    }
    else
    {
        if (d%n==0)cout<<n;
        else cout<<d%n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
