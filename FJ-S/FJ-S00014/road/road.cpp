#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1000,M=1e7+100;
struct node
{
	int x,y,z,flag;
}a[M],b[M];
int f[N],vd[20][N],c[N],v[N];
long long ans=0,cnt=0,t=0,minn=0;
int n,m,k;
int find(int x)
{
	if(x!=f[x]) return f[x]=find(f[x]);
	return x;
}
bool cmp(node x,node y)
{
	return x.z<y.z;
}
void dfs(int i,int x)
{
	if(i==k+1)
	{
		for(int i=1;i<=n+k;i++) f[i]=i;
		long long tot=0;t=0;
		for(int i=1;i<=cnt;i++)
		{
			int vi=0;
			int xx=b[i].x,y=b[i].y;
			if(b[i].flag==1)
			{
				 vi=xx;
			}
			if(b[i].flag==0||v[vi]==1)
			{
				int fx=find(xx),fy=find(y);
				if(fx==fy) continue;
				f[fx]=fy;
				tot+=b[i].z;
				t++;
				if(t==n+x-1) break;
			}
		}
		for(int i=1;i<=k;i++)
		{
			if(v[i+n]) tot+=c[i];
		}
		ans=min(ans,tot);
		return;
	}
	dfs(i+1,x);
	v[n+i]=1;
	dfs(i+1,x+1);
	v[n+i]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{ 
			scanf("%d",&vd[i][j]);
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x=a[i].x,y=a[i].y;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		t++;
		f[fx]=fy;
		b[++cnt]=a[i];
		ans+=a[i].z;
		if(t==n-1) break;
	}
	if(k<=0) 
	{
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[++cnt].x=n+i;
			b[cnt].y=j;
			b[cnt].z=vd[i][j];
			b[cnt].flag=1;
		}
	}
	sort(b+1,b+1+cnt,cmp);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}