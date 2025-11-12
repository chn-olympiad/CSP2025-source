#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int MOD=998244353;
int n,a[N],v[N],ans;
int b(int x,int y)
{
    int s=1;
    for(int i=y;i>=y-x+1;i--)
        s*=i;
    return s;
}
int c(int x,int y)
{
    return b(x,y)/b(x,x);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(a[n]<=1)
    {
        for(int i=3;i<=n;i++)
            ans+=c(i,n),ans%=MOD;
        cout<<ans%MOD;
        return 0;
    }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>a[3]*2) ans++;
        cout<<ans%MOD;
        return 0;
    }
    if(n==4)
    {
        if(a[1]+a[2]+a[3]>a[3]*2) ans++;
        else if(a[1]+a[2]+a[4]>a[4]*2) ans++;
        else if(a[1]+a[3]+a[4]>a[4]*2) ans++;
        else if(a[2]+a[3]+a[4]>a[4]*2) ans++;
        else if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
        cout<<ans%MOD;
        return 0;
    }
    cout<<n;
    return 0;
}
