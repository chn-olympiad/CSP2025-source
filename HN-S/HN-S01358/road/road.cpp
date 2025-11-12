#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
const int N=1e4+10,M=3e6+10;
int n,m,k;
struct Node{
	LL a,b,c;
};
Node r[M];
int num;
LL p[N],c[15],a[15][N];

int find(int x)
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}

bool cmp(Node x,Node y)
{
	return x.c<=y.c;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++)
	{
		LL a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		r[i]={a,b,c};
	}
	sort(r+1,r+m+1,cmp);
	LL ans=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		int a=r[i].a,b=r[i].b;
		int pa=find(a),pb=find(b);
		if(pa!=pb)
		{
			cnt++;
			ans+=r[i].c;
			p[find(b)]=p[find(a)];
		}
		if(pa==pb) continue;
		if(cnt==n-1) break;
	}
	printf("%lld",ans);
	
	return 0;
}
