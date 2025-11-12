#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105],n,m,p,b,c;
    cin>>n>>m;
    for(int i=0;i<=n*m-1;i++)
    {
        cin>>a[i];
    }
    p=a[0];
    for(int i=1;i<=n*m-1;i++)
        for(int j=1;j<=n*m-1;j++)
            if(a[j]>=a[j-1])swap(a[j],a[j-1]);
    for(int i=0;i<=n*m;i++)
        if(p==a[i])
        {
            b=i/n;
            c=i%n;
            if(b%2==0)cout<<b+1<<' '<<c+1;
            if(b%2==1)cout<<b+1<<' '<<n-c;
        }
    return 0;
}
