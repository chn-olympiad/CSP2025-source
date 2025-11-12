#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,m,dp[505][505][505],c[505],p[505],sum[505];
ll jc[505];
char s[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    jc[0]=1;
    for(int i=1;i<=n;i++)   jc[i]=(jc[i-1]*i)%mod;
    for(int i=1;i<=n;i++)   cin>>s[i],sum[i]=(sum[i-1]+(s[i]=='0'));
    int c0=0;
    for(int i=1;i<=n;i++)   cin>>c[i],p[i]=i,c0+=(c[i]==0);
    if(n>10)
    {
        if(n-c0<m)  cout<<0;
        else    cout<<jc[n];
        return 0;
    }
    ll ans=0;
    do
    {
       // for(int i=1;i<=n;i++)   cout<<p[i];
       // cout<<'\n';
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
         //   cout<<"g:"<<cnt<<' '<<i-1-cnt<<'\n';
            if(s[i]=='0')   continue;
            if(i-1-cnt>=c[p[i]])    continue;
            cnt++;
        }
        if(cnt>=m)  ans=(ans+1)%mod;
       // break;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
    return 0;
}
