#include<bits/stdc++.h>

using namespace std;
const int mod=99824453;
int n,m,s[510],c[510],cnt,v[501];
long long ans=0;
void dfs(int now,int use,int re)
{
	if(use+re==n)
	{
		if(use>=m)
		  ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			if(c[i]<=re||s[use+re+1]==0) dfs(i,use,re+1);
			else dfs(i,use+1,re);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		s[i]=ch-'0';
		cnt+=s[i];
	}
	int xx=0;
	for(int i=1;i<=n;i++) cin>>c[i],xx+=(c[i]==0);
	if(n<=10)
	{
		dfs(0,0,0);
		cout<<ans<<'\n';
		return 0;
	}
	if(cnt<m||m==n&&xx)
	{
		cout<<"0\n";
		return 0;
	}
	if(cnt==n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
}
