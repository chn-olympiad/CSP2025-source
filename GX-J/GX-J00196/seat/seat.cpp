#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[101],t,x,y,s;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    t=a[1];
    for(int i=1;i<=n*m;i++)
    {
        s=i;
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[j]>a[s]) s=j;
        }
        swap(a[s],a[i]);
    }
    for(int i=1;i<=n*m;i++)
    {
        if(t==a[i]) t=i;
    }
    x=floor((t-1)/n)+1;
    if(x%2==1) y=(t+n-1)%n+1;
    else y=n-(t+n-1)%n;
    cout<<x<<" "<<y;

    return 0;
}

