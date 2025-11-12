#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=510;
const ll p=998244353;
int n,m;
int s[MAXN],c[MAXN];
int ord[MAXN];
ll ans;
string str;
bool vis[MAXN];
int cnt;
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(cnt>=c[ord[i]])++cnt;
		else if(!s[i])++cnt;
	}
	return n-cnt>=m;
}
void dfs(int stp)
{
	if(stp>n)
	{
		if(check())ans=(ans+1)%p;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i])continue;
		ord[stp]=i;vis[i]=1;
		dfs(stp+1);
		vis[i]=0;
	}
}
ll jc[MAXN];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<n;++i)s[i+1]=str[i]-'0';
	for(int i=1;i<=n;++i)cin>>c[i],cnt+=(c[i]==0);
	if(n<=18)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(n-cnt<m)
	{
		cout<<0;
		return 0;
	}
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=(jc[i-1]*i)%p;
	cout<<jc[n];
	return 0;
}