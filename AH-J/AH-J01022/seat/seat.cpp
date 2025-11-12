#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[101];
    int ans=1;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    for(int i=2;i<=n*m;i++)if(a[i]>a[1])ans++;
    int d=ans/m,c=d%n;
    int z=n-c+1;
    int b=1+d;
    int x=1,y=1;
        if(ans<=m)cout<<1<<' '<<ans+m-2;
        else{
        if(d%2==0)cout<<b<<' '<<c;
        else cout<<b<<' '<<z;
        }
    return 0;
}
