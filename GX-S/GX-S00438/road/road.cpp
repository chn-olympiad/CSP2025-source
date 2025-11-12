#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=1000011;
int n,m,k;
int ans[101];
int cl[11];
int cre[11][N/10];
int f[N];
int dp[N][11];
struct ss
{
	int u,v,c;
}a[N];
int find(int x)
{
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void unionn(int x,int y)
{
	f[find(y)]=f[find(x)];
}
bool isuni(int x,int y)
{
	if(find(x)!=find(y)) return 0;
	else return 1;
}
bool cmp(ss a,ss b)
{
	return a.c<b.c;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&cl[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&cre[i][j]);
	}
	int cur=1;
	int num=0;
	for(int i=1;i<=m;i++)
	{
		ss now=a[i];
		if(isuni(now.u,now.v)==0)
		{
			unionn(now.u,now.v);
			num=num+now.c;
		}
	}
	cout<<num;
	return 0;
}
