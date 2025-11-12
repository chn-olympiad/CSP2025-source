#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],id[N],cnt;
bool vis[N];
char c[N];
bool check()
{
	int sum=0,tot=0;
	for(int i=1;i<=n;i++)
		if(c[i]=='1'&&a[id[i]]>tot)
			sum++;
		else
			tot++;
	return sum>=m;
}
void dfs(int cur)
{
	if(cur==n+1)
	{
		if(check())
			cnt++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		id[cur]=i,vis[i]=1;
		dfs(cur+1);
		id[cur]=vis[cur]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int p=1,fi=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]=='0')
			p=0;
		if(!fi&&c[i]=='1')
			fi=i;
	}
	if(p==1)
	{
		long long ans=1;
		for(long long i=1;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt+=(a[i]>fi-1);
	if(m==1)
	{
		long long ans=cnt;
		for(int i=1;i<n;i++)
			ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<cnt;
	return 0;
}

