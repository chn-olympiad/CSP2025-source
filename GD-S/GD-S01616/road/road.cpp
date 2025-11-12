#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
	int u,v,w; 
}num[2000010];
long long n,m,k,sum=INF,a[15][10010];
long long xum[20000];
long long find(long long x)
{
	if(xum[x]==x)return x;
	return xum[x]=find(xum[x]);
}
void merge(long long a,long long b)
{
	a=find(a),b=find(b);
	if(a!=b)
	{
		xum[a]=b;
	}
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
long long bum[20];
long long run()
{
	long long tot=0,tott=0,cum=0,ans=0;
	for(long long i=1;i<=k;i++)
	{
		if(!bum[i])continue;
		cum+=1;
		ans+=a[i][0];
		for(long long j=1;j<=n;j++)
		{
			tott+=1;
			num[m+tott].u=n+cum;
			num[m+tott].v=j;
			num[m+tott].w=a[i][j];
		}
	}
	sort(num+1,num+m+tott+1,cmp);
	for(long long i=1;i<=m+tott;i++)
	{
		long long u=num[i].u,v=num[i].v,w=num[i].w;
		if(find(u)!=find(v))
		{
			merge(u,v);
			ans+=w;
			tot++;
		}
		if(tot==n+cum-1)
		{
			return ans;
		}
	}
	return INF;
}
void dfs(long long now,long long x)
{
	if(x==0)
	{
		sum=min(sum,run());
	}
	for(long long i=now;i<=k;i++)
	{
		if(!bum[i])
		{
			bum[i]=1;
			dfs(i+1,x-1);
			bum[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>num[i].u>>num[i].v>>num[i].w;
	}
	for(long long i=1;i<=k;i++)
	{
		for(long long j=0;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(long long i=0;i<=k;i++)
	{
		for(long long j=1;j<=n+i;j++)xum[j]=j;
		dfs(1,i);
	}
	cout<<sum;
	return 0;
}
