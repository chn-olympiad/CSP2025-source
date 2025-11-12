/*
无论什么代价都在所不惜
没有可以思考的心智
没有可以屈从的意志
没有为苦难哭泣的声音
生于神于虚空之手
你必将封印在众人梦中散布瘟疫的障目之光
你是容器
你是空洞骑士 
*/
#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e4+50,M=2e6+10;
template<typename T>void qr(T& x)
{
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
struct node{int x,y,w;}a[M];
bool cmp(node n1,node n2){return n1.w<n2.w;}
int n,m,k,fa[N];
int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	qr(n);qr(m);qr(k);
	for(int i=1;i<=m;i++)
	{
		qr(a[i].x);qr(a[i].y);qr(a[i].w);
	}
	for(int i=1,x;i<=k;i++)
	{
		qr(x);
		for(int j=1;j<=n;j++)qr(a[(i-1)*n+j+m].w),a[(i-1)*n+j+m].x=i+n,a[(i-1)*n+j+m].x=j;
	}
	m+=n*k;n+=k;
	sort(a+1,a+m+1,cmp);
//	for(int i=1;i<=m;i++)printf("%d ",a[i].w);puts("");
	for(int i=1;i<=n;i++)fa[i]=i;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int tx=findfa(a[i].x),ty=findfa(a[i].y);
		if(fa[a[i].x]!=fa[a[i].y])
		{
//			printf("%d %d\n",a[i].x,a[i].y);
			fa[tx]=ty;ans+=a[i].w;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
4 4 1
1 2 4
2 4 5
3 4 6
1 3 3
0 1 2 3 0
*/
