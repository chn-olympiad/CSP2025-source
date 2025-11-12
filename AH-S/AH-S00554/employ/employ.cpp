#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=505,mod=998244353;
ll n,m,ans;
string str;
ll p[N],a[N];
bool vis[N];
void dfs(ll num)
{
	if(num==n+1)
	{
		ll sum=0,fail=0;
		for(int i=1;i<=n;i++)
		{
			if(fail>=p[a[i]]) fail++;
			else if(str[i-1]=='1') sum++;
				 else fail++;
			if(sum>=m) break;
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		a[num]=i;
		dfs(num+1);
		a[num]=0;
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>str;
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
	dfs(1);
	cout<<ans%mod;
	return 0;
}
