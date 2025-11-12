#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int MAXN=1e8+5;
struct node
{
	int nxt,to,va;
}ma[MAXN];
int head[N],cnt;
int n,m,k,u,v,w,c[15];
int uk[N];
void add(int v,int u,int w)
{
	ma[++cnt].to=v;
	ma[cnt].nxt=head[u];
	head[u]=cnt;
	ma[cnt].va=w;
}
int ans;
int fi[N];
int find(int x)
{
	if(x==fi[x]) return x;
	fi[x]=find(fi[x]);
	return fi[x];
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	fi[u]=v;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fi[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>uk[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int p=1;p<=n;p++)
			{
				if(j==p) continue;
				add(j,p,uk[j]+uk[p]);
				//cout<<k<<' '<<p<<' '<<uk[j]+uk[p]<<endl;
			}
		}
	}
	/*
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		cout<<ma[i].to<<' '<<ma[i].nxt<<' '<<ma[i].va<<endl;
	}
	for(int i=1;i<=n;i++) cout<<head[i]<<' ';
	cout<<endl;
	*/
	for(int i=1;i<=n;i++)
	{
		if(find(i)==find(1)) continue; 
		int minn=2e9,minv;
		for(int j=head[i];j;j=ma[j].nxt)
		{
			//cout<<ma[j].to<<' '<<ma[j].va<<endl;
			if(ma[j].va<minn)
			{
				minn=ma[j].va;
				minv=ma[j].to;
			}
		}
		//cout<<minn<<endl;
		merge(i,minv);
		ans+=minn;
	}
	cout<<ans;
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/
