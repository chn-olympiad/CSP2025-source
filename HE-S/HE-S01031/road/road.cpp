#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
}e[505050];
int f[505005],a[50][50500],c[500550];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(find(x)!=find(y))
	{
		f[x]=y;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	int cnt=n,ans=0;
	if(k==0)
	{
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(find(e[i].u)!=find(e[i].v))
			{
				ans+=e[i].w;
				merge(e[i].u,e[i].v);
				cnt--;
			}
			if(cnt==1)
			{
				break;
			}
		}
		cout<<ans<<endl;
	}
}
