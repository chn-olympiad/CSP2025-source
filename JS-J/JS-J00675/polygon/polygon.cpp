#include<bits/stdc++.h>
using namespace std;
int n, ans=0;
int f[5005];
int g[5005];
void dfs(int x)
{
	if(x>=n-1)
	{
		return;
	}
	g[x+1]+=g[x];
	if(g[x+1]>g[x+2])
	{
		ans++;
		dfs(x+1);
	}
	else
	{
		g[x+1]=f[x+1];
		dfs(x+1);
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>f[i];
		g[i]=f[i];
	}
	sort(f+1, f+n+1);
	sort(g+1, g+n+1);
	if(n==3)
	{
		if(f[1]+f[2]>f[3])
		{
			cout<<1<<endl;
			return 0;
		}
		else
		{
			cout<<0<<endl;
			return 0;
		}
	}
	dfs(1);
	cout<<ans<<endl;
	
	return 0;
}
