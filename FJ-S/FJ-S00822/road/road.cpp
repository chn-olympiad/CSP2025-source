#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[10][N];
int n,m,k,cnt=0,head[N];
struct Edge{
	int next,to,w;
}edge[N];
void add(int u,int v,int w)
{
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	int vp=0,op=0;
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		op+=c;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			vp++;
		}
	}
	if(vp==k*n)
	{
		cout<<op<<endl;
		return 0;
	}
	return 0;
}
//我要玩三国杀！！！
//窝这题补药爆零啊555
//窝要梯高组三等555 
//西西弗窝恨尼 
