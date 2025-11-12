#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
vector<int> c;
vector<bool> v;
int cc,cnt;
long long dfs(int x)
{
	if(x==n) return (cnt>=m?1:0);
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]) continue;
		v[i]=true;
		if(cc>=c[i]||s[x]=='0') cc++;
		else cnt++;
		ans=(ans+dfs(x+1))%mod;
		v[i]=false;
		if(cc>=c[i]||s[x]=='0') cc--;
		else cnt--;
	}
	return ans;
}
void solve()
{
	bool f=false;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			f=true;
			break;
		}
	}
	if(!f)
	{
		cout<<0;
		return;
	}
	v.resize(n);
	cout<<dfs(0);
}/*
void solve2()
{
	for(int i=0;i<n;i++)
	{
		if(c[i]!=0) cnt++;
	}
	if(cnt<m)
	{
		cout<<0;
		return;
	}
	long long fac=1;
	for(int i=2;i<=n;i++) fac=fac*i%mod;
	cout<<fac;
}*/
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;/*
	bool f=true;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			f=false;
			break;
		}
	}*/
	c.resize(n);
	for(int i=0;i<n;i++) cin>>c[i];
	//if(f) solve2();
	solve();
	return 0;
}
