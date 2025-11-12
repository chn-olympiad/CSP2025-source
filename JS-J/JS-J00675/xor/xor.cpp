#include<bits/stdc++.h>
using namespace std;
int n, k, ans1=0;
int f[500005];
int g[500005];
void dfs(int x)
{
	if(x>n)
	{
		return;
	}
	if(f[x]==k)
	{
		ans1++;
		dfs(x+1);
	}
	else if(f[x]>k)
	{
		f[x]=g[x];
		if(g[x]==k)
		{
			ans1++;
		}
		dfs(x+1);
	}
	else
	{
		int a=f[x]&f[x+1];
		int b=f[x]|f[x+1];
		int c=f[x+1];
		f[x+1]=b-a;
		dfs(x+1);
		f[x+1]=c;
	}
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>f[i];
		g[i]=f[i];
	}
	dfs(1);
	cout<<ans1<<endl;

	return 0;
}
