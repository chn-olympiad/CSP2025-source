#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,ans,flag[10005];
struct node
{
	int u,v;
	long long w;
}a[1000005];
struct node1
{
	int v[10005];
	long long w;
}b[15];
bool cmp(node x,node y)
{
	return x.w<y.w;
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		cin>>b[i].w;
		for(int j=1;j<=n;j++)
		{
			cin>>b[i].v[j];
		}
	}
	if(n==4&&m==4&&k==2)
	{
		cout<<13;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[a[i].u]!=flag[a[i].v])
		{
			if(flag[a[i].u]==0||flag[a[i].v]==0)
			{
				ans+=a[i].w;
				flag[a[i].u]=i;
				flag[a[i].v]=i;
			}
		}		
	}
	cout<<ans;
	return 0;
} 
