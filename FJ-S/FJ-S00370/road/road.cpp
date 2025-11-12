#include<bits/stdc++.h>
using namespace std;
const long long N=10050;
const long long M=2200050;
const long long INF=1e18;
long long head[N<<1],nxt[M<<1],to[M<<1],w[M<<1],cnt=0;
long long n,m,k,c[11],a[11][N];
struct node{
	long long id,len;
	bool operator <(const node &x) const{
		return x.len<len;
	}
};
void add(long long x,long long y,long long z)
{
	nxt[++cnt]=head[x];
	to[cnt]=y;
	w[cnt]=z;
	head[x]=cnt;
}
long long min_tree()
{
	
	priority_queue<node> q;
	long long vis[N]={0};
	long long dc=n;
	long long ret=0;
	q.push({1,0});
	while(dc)
	{
		node tmp=q.top();
		q.pop();
		long long x=tmp.id,dis=tmp.len;
		if(vis[x]) continue;
		vis[x]=1;
		ret+=dis;
		dc--;
		for(long long i=head[x];i;i=nxt[i])
		{
			if(!vis[to[i]])
			{
				q.push({to[i],w[i]});
			}
		}	
 }
	return ret;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	long long x,y,z;
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(long long i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(long long j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	printf("%lld",min_tree()); 
	return 0;
}
