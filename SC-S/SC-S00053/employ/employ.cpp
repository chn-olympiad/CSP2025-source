#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

int n,m,ans,a[1000],used[1000],z[1000];
string s;

bool check(int now)
{
	if(now<m) return false;
	int sum=0;
	for(int i=1;i<=now;++i)
	{
		if(s[i-1]=='0'||sum>=z[i]) ++sum;
	}
	if(now-sum>=m) return true;
	return false;
}

void dfs(int now)
{
	if(check(now-1))
	{
		++ans;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(used[i]) continue;
		used[i]=1;
		z[now]=a[i];
		dfs(now+1);
		used[i]=0;
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}








