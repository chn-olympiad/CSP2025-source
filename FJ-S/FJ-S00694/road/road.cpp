#include<bits/stdc++.h>//15:22 probaly true
using namespace std;
const long long N=1e4+11,M=1e6+11,INF=0x7fffffff;
long long n,m,k,cc,f[N],dan,sum=0,ans,d[N],gg;
bool b[N];
priority_queue<pair<int,int> > q;
struct zhx{
	long long u,v,w;
}c[M];
bool cmp(zhx a,zhx b)
{
	return a.w<b.w;
}
inline bool check(long long x)
{
	return b[(x-n)/n+1];
}
long long find(long long x)
{
	if(f[x]!=x)
		return f[x]=find(f[x]);
	return x;
}
inline void bs()
{
	for(long long i=1; i<=n+k; i++)
		f[i]=i;
	long long sum=ans,g=0,l=1,x,y,u,v,w;
	for(long long i=n; i<=cc; i++)
		q.push(make_pair(-c[i].w,i));
	while(g<n+gg-1)
	{
		while(!q.empty() && !check(q.top().second))
			q.pop();
		if(!q.empty() && (l>n-1 || (-q.top().first<=c[l].w)))
		{
			u=c[q.top().second].u,v=c[q.top().second].v,w=c[q.top().second].w;
			q.pop();
		}
		else
			u=c[l].u,v=c[l].v,w=c[l].w,l++;
		x=find(u),y=find(v);
		if(x==y)
			continue;
		g++;
		sum+=w;
		f[x]=y;
	}
//	cout<<sum<<endl;
	dan=min(dan,sum);
	return;
}
inline void dfs(long long x)
{
	if(x>k)
	{
		bs();
		return;
	}
	dfs(x+1);
	
	gg++;
	ans+=d[x];
	b[x]=true;
	dfs(x+1);
	
	gg--;
	ans-=d[x];
	b[x]=false;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long u,v,w,x,y;
	cin>>n>>m>>k;
	for(long long i=1; i<=m; i++)
		scanf("%lld%lld%lld",&c[i].u,&c[i].v,&c[i].w);
	sort(c+1,c+1+m,cmp);
	for(long long i=1; i<=n; i++)
		f[i]=i;
	for(long long i=1; i<=m; i++)
	{
		u=c[i].u,v=c[i].v,w=c[i].w;
		x=find(u),y=find(v);
		if(x==y)
			continue;
		sum+=w;
		c[++cc].u=u,c[cc].v=v,c[cc].w=w;
		f[x]=y;
		if(cc==n-1)
			break;
	}
	dan=sum;
//	cout<<dan<<endl;
	if(k==0)
	{
		printf("%lld",dan);
		return 0;
	}
//	cout<<"lbfsm\n";
	for(long long i=1; i<=k; i++)
	{
		scanf("%lld",&d[i]);
//		cout<<"lbfsm\n";
		for(long long j=1; j<=n; j++)
			scanf("%lld",&c[++cc].w),c[cc].u=n+i,c[cc].v=j;
	}
//	for(long long i=1; i<=cc; i++)
//		cout<<c[i].u<<' '<<c[i].v<<' '<<c[i].w<<endl;
	dfs(1);
	printf("%lld",dan);
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

//16:35 1.48s i5-8500
//16:53 still
U9 285K
*/
