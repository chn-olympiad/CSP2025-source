#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
	long long from,to,v;
};
vector<edge>edges;
char ch;
void read(long long &res)
{
	res=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
}
long long n,m,k,c[20],a[20][20010],ans=8e18,fa[20010];
bool bz[20];
long long find(long long x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void kruskal(long long val,long long c_cnt)
{
	for(long long i=1;i<=n+k;i++) fa[i]=i;
	long long sum=val,cnt=0,tot_p=n+c_cnt;
	for(auto e:edges)
	{
		long long from=e.from,to=e.to,v=e.v;
		if(from>n)
		{
			if(!bz[from-n])
				continue;
		}
		from=find(from);to=find(to);
		if(from!=to)
		{
			sum+=v;
			fa[to]=from;
			cnt++;
			if(cnt==tot_p-1) break;
		}
	}
	ans=min(ans,sum);
}
void work(long long now,long long sum,long long c_cnt)
{
	if(now>k)
	{
		kruskal(sum,c_cnt);
		return;
	}
	bz[now]=1;
	work(now+1,sum+c[now],c_cnt+1);
	bz[now]=0;
	work(now+1,sum,c_cnt);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(long long i=1;i<=m;i++)
	{
		long long from,to,v;
		read(from);read(to);read(v);
		edges.push_back(edge{from,to,v});
	}
	for(long long i=1;i<=k;i++)
	{
		read(c[i]);
		for(long long j=1;j<=n;j++)
		{
			read(a[i][j]);
			edges.push_back(edge{n+i,j,a[i][j]});
		}
	}
	sort(edges.begin(),edges.end(),[](edge a,edge b){return a.v<b.v;});
	work(1,0,0);
	printf("%lld\n",ans);
}
//14:56