#include<bits/stdc++.h>
using namespace std;
long long n,m,c[555],a[555],ans,jl[555];
char s[555];
void slove()
{
	int cnt=0,fai=0;
	for(int i=1;i<=n;i++)
	{
		if(fai>=c[a[i]])
		{
			fai++;
			continue;
		}
		if(s[i]=='1')
		{
			cnt++;
		}
		else
		{
			fai++;
		}
	}
	if(cnt>=m)
	{
		ans++;
	}
}
void dfs(int x)
{
	if(x==n+1)
	{
		slove();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(jl[i]==1)
		{
			continue;
		}
		jl[i]=1;
		a[x]=i;
		dfs(x+1);
		jl[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<endl;
}
