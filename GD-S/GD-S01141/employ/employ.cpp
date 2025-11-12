#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans,mod=998244353,p[505],bz[505];
char s[505];
void dfs(int k)
{
	if(k>n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(n-cnt<m)
			{
				return;
			}
			if(cnt>=c[p[i]])
			{
				cnt++;
				continue;
			}
			if(s[i]=='0')
			{
				cnt++;
			}
		}
		if(n-cnt>=m)
		{
			ans=(ans+1ll)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bz[i]==0)
		{
			p[k]=i;
			bz[i]=1;
			dfs(k+1);
			bz[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans; 
} 
