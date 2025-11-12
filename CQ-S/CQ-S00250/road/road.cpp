#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node
{
	long long u,v,w;
	bool operator <(const Node &x) const
	{
		return w<x.w;
	}
}e[1000005],e2[15][1000005];
long long n,m,k,cnt=0,ans=0,c[15],a[15][10005],f[10005],siz[10005];
bool vis[15]; 
priority_queue<Node> q;
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
long long lowbit(long long x)
{
	return x&-x;
}
long long find(long long x)
{
	return f[x]==x?f[x]:f[x]=find(f[x]);
}
long long merge(long long x,long long y)
{
	x=find(x),y=find(y);
	if(x==y)
	{
		return 0;
	}
	if(siz[x]>siz[y])
	{
		swap(x,y);
	}
	siz[y]+=siz[x];
	f[x]=y;
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)
	{
		f[i]=i,siz[i]=1;
	}
	for(long long i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			cin>>e2[i][j].w;
			e2[i][j].u=n+i,e2[i][j].v=j;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		if(merge(e[i].u,e[i].v))
		{
			e2[0][++cnt]=e[i];
			ans+=e[i].w;
		} 
	}
	sort(e2[0]+1,e2[0]+n,cmp);
	for(long long x=0;x<=(1<<k)-1;x++)
	{
	/*	long long sum=0,len=n+(__builtin_popcount(x))-1;
		for(long long i=1;i<=2*n;i++)
		{
			f[i]=i,siz[i]=1;
		}
		for(long long i=x;i>=1;i-=lowbit(i))
		{
			q.push(Node{__lg(lowbit(i))+1,1,e2[0][__lg(lowbit(i))+1].w});
			sum+=c[__lg(lowbit(i))+1];
		}
		while(cnt<len&&!q.empty())
		{
			Node x=q.top();
			q.pop();
			if(merge(e2[x.u][x.v].u,e2[x.u][x.v].v))
			{
				sum+=x.w; 
				cnt++;
			}
			if(x.v<n-(!x.u))
			{
				q.push(Node{x.u+1,x.v+1,e2[x.u+1][x.v+1].w});
			}
		}
		while(!q.empty())
		{
			Node x=q.top();
			q.pop();
		}
		ans=min(ans,sum);	*/	
	}
	cout<<ans<<endl;
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
*/
