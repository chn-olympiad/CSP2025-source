#include<bits/stdc++.h>
using namespace std;

long long n,m,a[105],c,r,s1,s2,b;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n*m;i++)cin >> a[i];
    s1=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[j]>a[i])
            {
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s1)s2=i;
    }
    if(s2%n==0)c=s2/n;
    else c=s2/n+1;
    if(c%2==0)r=n-s2%n+1;
    else if(s2%n==0)r=n;
    else r=s2%n;
    cout << c << ' ' << r;

    return 0;
}
