#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,MOD=998244353;
int n,m,a[N],b[N],tmp;
long long ans;
string s;
bool f[N];
map<int,int>m2;
void dfs(int x,int s)
{
	if (x>tmp)
	{
		ans=(ans+(s>=m))%MOD;
		return;
	}
	for (int i=1;i<=n;++i)
	{
		if (f[i])
			continue;
		f[i]=1;
		if (b[x]-s>a[i])
			dfs(x+1,s+1);
		else
			dfs(x+1,s);
		f[i]=0;
	}
}
void dfs2(int x,int s)
{
	if (x>n)
	{
		ans+=(s>=m);
		return;
	}
	for (int i=1;i<=n;++i)
	{
		if (f[i])
			continue;
		f[i]=1;
		if (m2[x]&&x-s>a[i])
			dfs2(x+1,s+1);
		else
			dfs2(x+1,s);
		f[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	long long num=1;
	s=" "+s;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		if (s[i]-'0')
			b[++tmp]=i,
			m2[i]=i;
	}
	if (n<=23)
	{
		dfs2(1,0);
		cout<<ans<<"\n";
		return 0;
	}
	for (int i=1;i<=n-tmp;++i)
		num=(num*(n-tmp-i+1)%MOD)%MOD;
	dfs(1,0);
	cout<<ans*num<<"\n";
	return 0;
}
