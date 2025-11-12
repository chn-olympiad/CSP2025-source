#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    int q;
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i;j<=n*m;j++)
        {
            if(a[i]<a[j]) swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(x==a[i])
        {
            q=i;
            break;
        }
    }
    int s=q/n;
    int d=q%n;
    int ans1;
    if(d==0) ans1=q/n;
    else ans1=s+1;
    int ans2=0;
    if(d==0)
    {
        if(s%2==1) ans2=n;
        if(s%2==0) ans2=1;
    }
    if(d!=0)
    {
        if(ans1%2==0) ans2=n-d+1;
        if(ans1%2==1) ans2=d;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
