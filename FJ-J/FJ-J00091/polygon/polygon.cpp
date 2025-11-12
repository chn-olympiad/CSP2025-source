#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
int n;
int a[MAXN];
bool dis[MAXN];
int c[MAXN];
int ans=0;
bool uv(int v)
{
	int maxn=0;
	int sum=0;
	for(int i=1;i<=v;i++)
	{
		maxn=max(maxn,c[i]);
		sum+=c[i];
	}
	return sum>2*maxn;
}
void dfs(int v)
{
	if(v>=3&&uv(v))
	{
		ans++;
	}
	for(int i=v;i<=n;i++)
	{
		if(dis[i])continue;
		dis[i]=true;
		c[v+1]=i;
		dfs(v+1);
		dis[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
