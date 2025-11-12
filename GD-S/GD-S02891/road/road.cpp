#include<bits/stdc++.h>
using namespace std;
long long n,m,k,xz[20][11000],sum=0,f[11000];
struct hhw
{
	long long v,w,u,c;
}r[2001000];
bool cmp(hhw x,hhw y)
{
	return x.w<y.w;
}
long long find(long long x)
{
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
bool tf[11000];
int main()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long i=1;i<=m;i++) cin>>r[i].u>>r[i].v>>r[i].w;
	sort(r+1,r+1+m,cmp);
	for(long i=1;i<=n;i++) f[i]=i;
	for(long i=1;i<=m;i++)
	{
		if(find(r[i].u)!=find(r[i].v))
		{
			f[find(r[i].u)]=find(r[i].v);
			sum+=r[i].w;
		}
	}
	for(long i=1;i<=k;i++)
	{
		cin>>xz[i][0];
		for(long long j=1;j<=n;j++)
		{
			cin>>xz[i][j];
		}
	}
	cout<<sum;
	return 0;
 } 
