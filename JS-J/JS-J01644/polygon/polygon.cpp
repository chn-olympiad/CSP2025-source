#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int mod=998244353;
int a[N],n,ans,sm[N];
void dfs(int u,int sum,int maxn,int cnt)
{
    if (u==n+1)
    {
        if (cnt>=3&&sum>2*maxn)
        {
            ans++;
            ans%=mod;
        }
        return ;
    }
    if (sum+sm[n]-sm[u-1]<=2*maxn)
    {
        return ;
    }
    if (n-u+1+cnt<3) return ;
    dfs(u+1,sum,maxn,cnt);
    dfs(u+1,sum+a[u],max(maxn,a[u]),cnt+1);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if (n<=20)
    {
        cout<<n<<endl;
        for (int i=1; i<=n; i++) cin>>a[i],sm[i]=sm[i-1]+a[i];
        dfs(1,0,0,0);
        cout<<ans%mod<<endl;
    }
    else
    {
		int mx=0;
        for (int i=1; i<=n; i++) cin>>a[i],mx=max(mx,a[i]);
        if (mx==1){
			int ans=1;
			for (int i=1;i<=n;i++){
				ans*=2;
				ans%=mod;
			}
			ans-=1+n+n*(n-1)/2;
			cout<<ans%mod<<endl;
		}
    }
    return 0;
}
