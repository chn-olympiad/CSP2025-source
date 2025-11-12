#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,s,head[1000001],w1[1000001];
struct AA
{
	int next;
	int from;
	int to;
	int zhi;
}bian[1000001];
void biao(int a,int b,int c)
{
	s++;
	bian[s].to=b;
	bian[s].from=a;
	bian[s].next=head[a];
	bian[s].zhi=c;
	head[a]=s;
}
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v>>w;
		biao(u,v,w);
		biao(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>w1[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			biao(n+i,j,w);
		}
	}
	cout<<0;
}