#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    long long p=a[1];
    sort(a+1,a+n*m+1);
    long long pai=0;
    for(long long i=n*m;i>=1;i--)
    {
        if(a[i]==p)
        {
            pai=n*m+1-i;
        }
    }
    long long x,y;
    y=(pai+m-1)/m;
    if(y%2==0)
    {
        x=n+1-(pai%m);
        if(x==n+1)
        {
            x=1;
        }
    }
    else{
        x=pai%m;
        if(x==0)
        {
            x=n;
        }
    }
    cout<<y<<' '<<x;
    return 0;
}
