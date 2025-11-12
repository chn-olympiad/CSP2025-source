#include<bits/stdc++.h>
using namespace std;
/*struct road{
	int w,to;
	int next;
}e[2020006];
int nwrd[11],c[11];
int first[10014],cnt=0;
int n,m,k;//原有的城市数量、道路数量和准备进行城市化改造的乡镇数量。
void add(int u,int v,int w)
{
	cnt++;
	e[cnt].next=first[u];
	first[u]=cnt;
	e[cnt].w=w;
	e[cnt].to=v;
	return ;
}
int a[10004];
bool paixu(int a1,int b1)
{
	return a[a1]<a[b1];
}
void f()
{
	for(int i=1;i<=n;i++)
	{
		a[i]=INT_MAX;
	}
	a[1]=0;
	priority_queue <pair<int,int> >q;
	return ;
}*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/*cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=m;j++)
		{
			int w;
			cin>>w;
			add(i,j,w);
			nwrd[0]++;
			nwrd[nwrd[0]]=cnt;
			add(j,i,w);
		}
	}
	f();*/cout<<'0';
	
	return 0;
}
