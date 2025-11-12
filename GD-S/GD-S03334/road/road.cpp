#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
//#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k,fa[N],c[11][N];
long long ans=9223372036854775807;
struct node{int x,y,w;}a[N],b[N],d[N];
bool cmp(node x,node y){return x.w<y.w;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}
long long mst()
{
	long long cnt=0;
	sort(d+1,d+1+m,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=d[i].x,y=d[i].y,w=d[i].w;
		if(find(x)==find(y))continue;
		fa[fa[x]]=fa[y];
		fa[x]=y;
		cnt+=w;
	}
	return cnt;
}
signed main()
{
	fre("road");
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++)read(a[i].x),read(a[i].y),read(a[i].w);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int now=0,WW=0;
	for(int i=1;i<=m;i++)
	{
		int x=a[i].x,y=a[i].y;
		if(find(x)==find(y))continue;
		fa[fa[x]]=fa[y];
		now++,b[now]=a[i];
	}
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)read(c[i][j]);//scanf("%lld",&c[i][j]);
	for(int i=0;i<(1<<k);i++)
	{
		long long cnt=0;
		m=n-1;
		for(int i=1;i<n;i++)m++,d[m]=b[i];
		for(int j=1;j<=k;j++)
		{
			if((i>>(j-1))&1)
			{
				cnt+=c[j][0];
				for(int l=1;l<=n;l++)
				{
					m++,d[m]=((node){n+j,l,c[j][l]});
				}
			}
		}
		if(cnt<ans)ans=min(ans,cnt+mst());
	}
	printf("%lld",ans);
}
