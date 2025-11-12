#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+10,M=1e6+10;
int n,m,k,num;
int c[N],a[15][N],f[N];
ll ans=1e18;
bool p[N];
struct str
{
	int x,y,z;
}b[M],v[N*10];
bool cmp(str a,str b)
{
	return a.z<b.z;
}
int find(int k)
{
	return f[k]==k?k:f[k]=find(f[k]);
}
ll solve()
{
	ll ans=0;
	int cnt=n,t=n-1;
	for(int i=1;i<n;i++)
		v[i]=b[i];
	for(int i=1;i<=k;i++)
		if(p[i])
		{
			ans+=c[i];
			cnt++;
			for(int j=1;j<=n;j++)
				v[++t]={cnt,j,a[i][j]};
		}
	sort(v+1,v+1+t,cmp);
	for(int i=1;i<=cnt;i++)
		f[i]=i;
	for(int i=1;i<=t;i++)
	{
		int &x=v[i].x,&y=v[i].y,&z=v[i].z;
		if(find(x)==find(y))continue;
		f[find(x)]=find(y);
		ans+=z;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int &x=b[i].x,&y=b[i].y,&z=b[i].z;
		if(find(x)==find(y))continue;
		f[find(x)]=find(y);
		b[++num]=b[i];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=(1<<k);i++)
	{
		ans=min(ans,solve());
		for(int j=1;j<=k;j++)
			if(p[j])p[j]=0;
			else
			{
				p[j]=1;
				break;
			}
	}
	cout<<ans;
	return 0;
}
