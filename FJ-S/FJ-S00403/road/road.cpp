#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,head[111111],f[111111],ans;
struct node{
	int start,finish,money;
}a[111111];
bool cmp(node x,node y)
{
	return x.money<y.money;
}
int find(int x)
{
	if(f[x]==x)
	return x;
	return f[x]=find(f[x]);
}
struct edge{
	int to,next,w;
}t[111111];
void addedge(int u,int v,int w)
{
	cnt++;
	t[cnt].to=v;
	t[cnt].next=head[u];
	head[u]=cnt;
	t[cnt].w=w;
}
void kruscal()
{
	int p=0;
	for(int i=1;i<=m;i++)
	{
		int k1=find(a[i].start),k2=find(a[i].finish);
		if(k1!=k2)
		{
			p++;
			ans+=a[i].money;
			f[k2]=k1;
		}
		if(p==n-1)
		break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		f[i]=i;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i].start>>a[i].finish>>a[i].money;
		}
		sort(a+1,a+m+1,cmp);
		kruscal();
		cout<<ans;
		return 0;
	}
	return 0;
}
