#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],x,pos;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>x;
    a[0]=111;
    for(int i=1;i<n*m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+m*n);
    for(int i=0;i<=n*m-1;i++)
    {
        if(a[i+1]>x)
        {
            pos=i+1;
            break;
        }
    }
    int l,r;
    pos=n*m-pos;
    l=(pos-1)/n+1;
    if(l%2==1)
    {
        r=(pos-1)%n+1;
    }
    else
    {
        r=m-(pos-1)%n;
    }
    cout<<l<<" "<<r;
    return 0;
}
