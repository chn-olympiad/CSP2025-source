#include <bits/stdc++.h>
#define MAXN 10010
#define MAXM 1000010
using namespace std;

int n,m,c,bc[MAXN],ans=0;

struct User_road
{
	int s,e,v;
}road[MAXM];

bool cmp(User_road x,User_road y)
{
	return x.v<y.v;
}

int find(int x)
{
	if(bc[x]!=x) bc[x]=find(bc[x]);
	return bc[x];
}

bool cheak(int x,int y)
{
	if(find(x)!=find(y)) return 1;
	else return 0;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>c;
	for(int i=1,s,e,v;i<=m;i++)
	{
		scanf("%d%d%d",&s,&e,&v);
		road[i].s=s;
		road[i].e=e;
		road[i].v=v;
	}
	sort(road+1,road+1+m,cmp);
	for(int i=1;i<=n;i++) bc[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(cheak(road[i].s,road[i].e))
		{
			ans+=road[i].v;
			bc[find(road[i].s)]=bc[find(road[i].e)];
		}
	}
	cout<<ans;
	return 0;
}
