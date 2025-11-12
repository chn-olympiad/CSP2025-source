#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,ans;
} a[1000005];
int n,m,k,b[15],c[15][10005],minn=0;
bool bb[15][10005];
void dfs(int j,int cnt,int i)
{
	if(j>m)
	{
		minn=min(cnt,minn);
		return;
	}
	if(c[i][a[j].u]+c[i][a[j].v]>a[j].ans+min(c[i][a[j].u],c[i][a[j].v]) && !bb[i][a[j].u] && !bb[i][a[j].v])
	{
		bb[i][a[j].u]=1;
		bb[i][a[j].v]=1;
		dfs(j+1,cnt-c[i][a[j].u]-c[i][a[j].v]+a[j].ans+min(c[i][a[j].u],c[i][a[j].v]),i);
	}
	bb[i][a[j].u]=0;
	bb[i][a[j].v]=0;
	dfs(j+1,cnt,i);
}
int main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin>>n>>m>>k;
 	for(int i=1;i<=m;i++)
 	{
 		cin>>a[i].u>>a[i].v>>a[i].ans;
 		minn+=a[i].ans;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
		int cnt=b[i];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			cnt+=c[i][j];
		}
		dfs(1,cnt,i);
	}
	cout<<minn;
	return 0;
}
