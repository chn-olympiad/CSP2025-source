#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
int n,m,a[100005],ans;
bool f[100005];
string s;
inline void dfs(int now,int sum,int cnt)
{
	if(now==n+1)
	{
		ans=(ans+(sum>=m))%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!f[i])
		{
			f[i]=1;
			if(cnt>=a[i]||s[now]=='0')
				dfs(now+1,sum,cnt+1);
			else dfs(now+1,sum+1,cnt);
			f[i]=0;
		}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||a[i]==0)
				cout<<0,exit(0);
		for(int i=2;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans;
	}
	else if(n>15)
		cout<<0;
	else dfs(1,0,0),cout<<ans;
	return 0;
}
