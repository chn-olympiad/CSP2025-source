#include<bits/stdc++.h>
using namespace std;
long long a[22]={0},vis[22]={0};
long long n,m;
char s[22];
long long c[22],ans=0;
void dfs(int x)
{
	if(x<=n)
	{
		for(long long i=1;i<=n;i++)
			if(!vis[i])
			{
				vis[i]=1;
				a[x]=i;
				dfs(x+1);
				vis[i]=0;
			}
	}
	else
	{
		int sum=0;
		for(long long i=1;i<=n;i++)
		{
			if(sum>=c[a[i]]) sum++;
		}
		if(n-sum>=m) ans++;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
} 

