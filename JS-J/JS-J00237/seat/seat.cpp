#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,R;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    int t;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==R)
        {
            t=i;
        }
    }
    int ka=t%(2*m),kb=t/(2*m),h,l=2;
    if(ka==0)
    {
        h=1;
    }
    else if(ka<=m)
    {
        h=ka;
        l=1;
    }
    else
    {
        h=2*m-ka+1;
    }
    l=l+kb*2;
    cout<<l<<' '<<h;
    return 0;
}
