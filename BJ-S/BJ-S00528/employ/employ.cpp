#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,mod=998244353;
int n,m,a[N],cnt;char c[N];bool flag=true,vis[N],flag2=true;ll ans;
inline int fac(int n){ll ans=1;for(int i=1;i<=n;i++) ans=ans*i%mod;return ans;}
inline void dfs(int cur,int cnt)
{
    if(cur>n){ans+=(n-cnt>=m);return;}
    for(int i=1;i<=n;i++) if(!vis[i]) vis[i]=true,dfs(cur+1,cnt+(cnt>=a[i]||c[cur]=='0')),vis[i]=false;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i],flag&=(c[i]-'0'),flag2&=(c[i]=='0');
    for(int i=1;i<=n;i++) cin>>a[i],cnt+=bool(a[i]);
    if(flag2){cout<<0;return 0;}
    if(m==n){cout<<(cnt==n&&flag)*fac(n);return 0;}
    if(n<=10){dfs(1,0);cout<<ans;return 0;}
    sort(a+1,a+n+1);ans=1;
    int C=0;
    for(int i=1;i<=n;i++) if(c[i]-'0')
    {
        int pos=lower_bound(a+1,a+n+1,i)-a-1;
        ans=ans*max(0,pos-C)%mod;
        C++;
    }
    ans=ans*fac(n-C)%mod;
    cout<<(fac(n)-ans+mod)%mod;
    return 0;
}