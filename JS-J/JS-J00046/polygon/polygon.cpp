#include<bits/stdc++.h>
using namespace std;
int n,x,a[8],ans=0,m;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    m=max(a[1],a[2]);
    m=max(m,a[3]);
    m=2*m;
    x=a[1]+a[2]+a[3];
    if(x>m)
        ans++;
    if(n<3)
        ans=0;
    cout<<ans;
    return 0;
}
