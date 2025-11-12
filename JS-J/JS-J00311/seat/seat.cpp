#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1008],b[1008];
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,v;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    t=a[1];
    sort(a+1,a+n*m+1,greater<int>{});
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t) v=i;
    }
    int k=v/n;
    int p=v%n;
    if(k%2==1)
    {
        if(p!=0)
            cout<<k+1<<" "<<n-p+1;
        else cout<<k<<" "<<1;
    }
    else
    {
        if(p!=0) cout<<k+1<<" "<<p;
        else cout<<k<<" "<<n;
    }
    return 0;
}
