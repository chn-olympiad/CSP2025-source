#include<bits/stdc++.h>
using namespace std;
struct b{
	long long u,v,w;
}a[2000000+5];
long long d[10000+15][2],c[10000+5][10000+5];
bool cmp(b x,b y)
{
	return x.w<y.w;
}
bool chack(int x,int y)
{ 
	return x==y or c[x][y] or c[y][x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,ans=0,cnt=0,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>a[i].u>>a[i].v>>a[i].w;
	if(k>0)
	{
		for(int i=1;i<=k;++i)
		{
			int x;
			cin>>x;
			ans+=x;
			for(int j=1;j<=n;++j)
			{
				cin>>a[m+(i-1)*n+j].w;
				a[m+(i-1)*n+j].u=m+i;
				a[m+(i-1)*n+j].v=j;
			}
		}
		sort(a+1,a+1+m+k*n,cmp);
		for(int i=1;i<=m+k*n;++i)
		{
			if(d[a[i].u][0] and d[a[i].v][0] and chack(d[a[i].u][1],d[a[i].v][1]))
				continue;
			ans+=a[i].w;
			cnt++;
			if(cnt==n-1+k)
			{
				cout<<ans;
				return 0;
			}
			if(!chack(d[a[i].u][1],d[a[i].v][1]) and d[a[i].u][1] and d[a[i].v][1])
			{
				c[d[a[i].u][1]][d[a[i].v][1]]=1;
			}
			if(d[a[i].u][0] and d[a[i].v][0]);
			else if(d[a[i].u][0])
			{
				d[a[i].v][0]=1;
				d[a[i].v][1]=d[a[i].u][1];
			}
			else if(d[a[i].v][0])
			{
				d[a[i].u][0]=1;
				d[a[i].u][1]=d[a[i].v][1];
			}
			else
			{
				d[a[i].u][0]=d[a[i].v][0]=1;
				d[a[i].u][1]=d[a[i].v][1]=sum++;
			}
		}
	}
	else
	{
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;++i)
		{
			if(d[a[i].u][0] and d[a[i].v][0] and chack(d[a[i].u][1],d[a[i].v][1]))
				continue;
			ans+=a[i].w;
			cnt++;
			if(cnt==n-1)
			{
				cout<<ans;
				return 0;
			}
			if(!chack(d[a[i].u][1],d[a[i].v][1]) and d[a[i].u][1] and d[a[i].v][1])
			{
				c[d[a[i].u][1]][d[a[i].v][1]]=1;
			}
			if(d[a[i].u][0] and d[a[i].v][0]);
			else if(d[a[i].u][0])
			{
				d[a[i].v][0]=1;
				d[a[i].v][1]=d[a[i].u][1];
			}
			else if(d[a[i].v][0])
			{
				d[a[i].u][0]=1;
				d[a[i].u][1]=d[a[i].v][1];
			}
			else
			{
				d[a[i].u][0]=d[a[i].v][0]=1;
				d[a[i].u][1]=d[a[i].v][1]=sum++;
			}
		}
	}
	return 0;
}
