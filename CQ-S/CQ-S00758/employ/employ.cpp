#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans;
string s;
int a[21],bo[21];
void dfs(int x,int cnt)
{
	if(cnt>n-m) return;
	if(x>n)
	{
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bo[i]) continue;
		bo[i]=1;
		if(cnt>=a[i]||s[x-1]=='0') dfs(x+1,cnt+1);
		else dfs(x+1,cnt);
		bo[i]=0;
	}
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
//I am not in danger, I am the danger.
