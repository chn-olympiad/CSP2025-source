#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[111111],cnt,c[22],a[22][11111],d[22],z[22];
long long sum,ans;
struct node
{
	int u,v,w;
};
node b[1111111],fb[1111111],b2[1111111];
vector<node>ab[22];

node mk(int u,int v,int w)
{
	node x;
	x.u=u;
	x.v=v;
	x.w=w;
	return x;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
long long find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void slove(int sl,int m,long long c)
{
//	sort(b2+1,b2+m+1,cmp);
	long long sum=0;
	int cnt=0;
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x=b2[i].u,y=b2[i].v,z=b2[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy)
		{
			continue;
		}
		sum+=z;
		cnt++;
		fa[fx]=fy;
		if(cnt==sl-1)
		{
			break;
		}
	}
	ans=min(ans,sum+c);
}
void dfs(int x)
{
	if(x==k+1)
	{
//		for(long long i=1;i<=n-1;i++)
//		{
//			b2[i]=fb[i];
//		}
		int sl=n,m=0;
		long long s=0;
		for(int i=0;i<=k;i++)
		{
			z[i]=0;
		}
		while(1)
		{
			int minn=2e9,mind=0;
			for(int i=0;i<=k;i++)
			{
				if(d[i]==0||z[i]==ab[i].size())
				{
					continue;
				}
				if(ab[i][z[i]].w<minn)
				{
					minn=ab[i][z[i]].w;
					mind=i;
				}
			}
			if(minn==2e9)
			{
				break;
			}
			m++;
			b2[m]=ab[mind][z[mind]];
			z[mind]++;
		}
				
		for(int i=1;i<=k;i++)
		{
			if(d[i]==1)
			{
				sl++;
				s+=c[i];
/*				for(long long j=1;j<=n;j++)
				{
					m++;
					b2[m].u=sl;
					b2[m].v=j;
					b2[m].w=a[i][j];
				}*/
			}
		}
		slove(sl,m,s);
		return;
	}
	d[x]=1;
	dfs(x+1);
	d[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x=b[i].u,y=b[i].v,z=b[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy)
		{
			continue;
		}
		sum+=z;
		cnt++;
		ab[0].push_back(b[i]);
//		fb[cnt]=b[i];
		fa[fx]=fy;
		if(cnt==n-1)
		{
			break;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			ab[i].push_back(mk(n+i,j,a[i][j]));
		}
		sort(ab[i].begin(),ab[i].end(),cmp);
	}
	ans=sum;
	d[0]=1;
	dfs(1);
	cout<<ans;
}
