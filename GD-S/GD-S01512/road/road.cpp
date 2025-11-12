#include<iostream>//road 最小生成树 prim
#include<algorithm>
#include<cstring>
#include<queue>
#define PII pair<int,int>
using namespace std;
const int N=5e7+10,M=1e4+50;
int p[N];
int n,m,t,t1;
int e[N],ne[N],h[N],w[N],idx;
int pri[M],dist[M];
bool f[M],f1[M];
int fr[M];
long long sum;
void add(int a,int b,int c)
{
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void prim()
{
	priority_queue< PII,vector<PII>,greater<PII> > q;
	q.push({0,1});
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	memset(fr,0x3f,sizeof fr);
	while(!q.empty())
	{
		PII t=q.top();
		q.pop();
		int x=t.first,y=t.second;
		if(f1[y])
			continue;
		f1[y]=1;
		if(y!=1)
			sum+=fr[y];
		for(int i=h[y];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(y<=t1)
				fr[j]=min(fr[j],w[i]);
			if(dist[y]+w[i]<=dist[j])
			{
				f[y]=1;
				fr[j]=min(fr[j],w[i]);
				dist[j]=dist[y]+w[i];
				q.push({dist[j],j});
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%d %d %d",&n,&m,&t);
	t1=n;
	int n1;
	for(int i=1,n1=1;i<=m;i++,n1+=2)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c),add(b,a,c);
	}
	int o=n;
	for(int i=1;i<=t;i++)
	{
		o++;
		int a;
		scanf("%d",&a);
		pri[i]=a;
		for(int j=1;j<=n;j++)
		{
			int b;
			scanf("%d",&b);
			add(j,o,b+a),add(o,j,b);
		}
	}
	n=o;
	prim();
	for(int i=n,j=1;j<=t;j++,i--)
		if(!f[i])
			sum-=fr[i];
	printf("%lld",sum);
	return 0;
}
