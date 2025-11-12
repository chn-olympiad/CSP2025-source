#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100+10],b,c,d;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    sort(a,a+1+n*m);
    for(int i=1;i<=n*m;i++)
    {

        if(a[i]==b)
        {
            if(i-1<=n)
            {
                c=1;
                cout<<1<<' ';
            }
            else
            {
                c=(i-1)/n+1;
                cout<<(i-1)/n+1<<' ';
            }
            if(c%2==0)
            {
                d=(i-1)-(c-1)*n;
                cout<<n-d+1;
            }
            else
            {
                d=(i-1)-(c-1)*4;
                cout<<d;
            }
        }
    }
    return 0;
}
