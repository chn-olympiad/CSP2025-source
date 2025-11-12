#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=2e6+5;
int n,m,k,f,mi=1e18,c[15],fa[N],x[M],y[M],z[M],a[15][N];
struct Node
{
	int x,y,z;
}hh[M];
bool cmp(Node x,Node y)
{
	return x.z<y.z;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		hh[i].x=x[i],hh[i].y=y[i],hh[i].z=z[i];
	}
	sort(hh+1,hh+m+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	if(k==0)
	{
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int fx=find(hh[i].x),fy=find(hh[i].y);
			if(fx!=fy)
			{
				merge(fx,fy);
				ans+=hh[i].z;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		
		cin>>c[i];
		if(c[i]) f=1;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(!f)
	{
		int ans=0,dq=m;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				++dq;
				hh[dq].x=i+n,hh[dq].y=j,hh[dq].z=a[i][j];
			}
		}
		sort(hh+1,hh+dq+1,cmp);
		for(int i=1;i<=dq;i++)
		{
			int fx=find(hh[i].x),fy=find(hh[i].y);
			if(fx!=fy)
			{
				merge(fx,fy);
				ans+=hh[i].z;
			}
		}
		cout<<ans;
		return 0;
	}
	int cs=pow(2,k)-1;
	for(int i=0;i<=cs;i++)
	{
		int er[15],td=i,cnt=0,dq=m,ans=0;
		while(td)
		{
			er[++cnt]=td%2;
			if(er[cnt]) ans+=c[cnt];
			td/=2;
		}
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=m;j++) hh[j].x=x[j],hh[j].y=y[j],hh[j].z=z[j];
		for(int j=1;j<=cnt;j++)
		{
			if(!er[j]) continue;
			for(int w=1;w<=n;w++)
			{
				hh[++dq].x=j+n;
				hh[dq].y=w;
				hh[dq].z=a[j][w];
			}
		}
		sort(hh+1,hh+dq+1,cmp);
		for(int i=1;i<=dq;i++)
		{
			int fx=find(hh[i].x),fy=find(hh[i].y);
			if(fx!=fy)
			{
				merge(fx,fy);
				ans+=hh[i].z;
			}
		}
		mi=min(mi,ans);
	}
	cout<<mi;
	return 0;
}
