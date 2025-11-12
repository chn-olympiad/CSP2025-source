#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node{
	int x,y,w;
}o[4000005];
int n,m,k,a[N],cnt,f[N];
int find(int x)
{
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int kruscal()
{
	int res=0,out=0;
	for(int i=1;i<=cnt;i++)
	{
		if(find(o[i].x)!=find(o[i].y))
		{
			res+=o[i].w;
			f[o[i].y]=find(o[i].x);
			out++;
		}
		if(out==n-1)break;
	}
	return res;
}
bool cmp(node A,node B)
{
	return A.w<B.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,vs,ws;
		scanf("%d%d%d",&u,&vs,&ws);
		o[++cnt].x=u;
		o[cnt].y=vs;
		o[cnt].w=ws;
		o[++cnt].x=vs;
		o[cnt].y=u;
		o[cnt].w=ws;
	}
	int flag=1;
	for(int i=1;i<=k;i++)
	{
		int c;
		scanf("%d",&c);
		flag=c;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			flag+=a[j];
		}
	}
	if(!flag)cout<<0;
	else
	{
		sort(o+1,o+1+cnt,cmp);
		cout<<kruscal();
	}
	return 0;
}
