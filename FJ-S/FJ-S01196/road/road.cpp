#include <bits/stdc++.h>
using namespace std;
#define N 10010
#define M 1000010
#define K 20
struct edge
{
	int u,v,w;
}e[M];
int f[N],n,m,k,bc[K],cr[K][N],head=0,now=0,maxn=0;
long long ans=0;
bool flag=0;
bool cmp(edge a1,edge b1)
{
	return a1.w<b1.w;
}
int find(int ed)
{
	if(f[ed]==ed)return ed;
	f[ed]=find(f[ed]);
	return f[ed];
}
void add()
{
	++now;++head;
	while(find(e[now].u)==find(e[now].v))now++;
	e[head]=e[now];
	f[find(e[now].u)]=f[find(e[now].v)];
	ans=ans+e[now].w;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&bc[i]);
		if(bc[i]!=0)flag=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cr[i][j]);
			if(cr[i][j]!=0)flag=1;
		}
	}
	if(flag==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		add();
	}maxn=e[head].w;
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

