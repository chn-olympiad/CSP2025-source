#include<bits/stdc++.h>
using namespace std;
int n,m,q;
string s;
int c[510],p[510],v[510];
long long sum,num,ans,mod=998244353;
void dfs(int k)
{
	if(k==n+1)
	{
		num=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0'||num>=c[p[i+1]]) num++;
			if(n-num<m) break;
		}
		if(n-num>=m)
		{
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			p[k]=i;
			dfs(k+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]=='0')
		{
			q=1;
			break;
		}
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(!q||m==1)
	{
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans;
	}
	cout<<0;
	return 0; 
}
