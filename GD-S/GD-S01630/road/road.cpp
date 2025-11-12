#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[11][11000],mn=9e18,f[11000];
struct sut
{
	long long u,v,w;
}s[1100000],vt[2100000],qt[2100000];
bool b[11];
bool cmp(sut px,sut py)
{
	return px.w<py.w;
}
long long findf(long long x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=findf(f[x]);
}
void krksx()
{
	long long d=0;
	for(long long i=1;i<=n;i++)
	{
		f[i]=i;
	}
	sort(s+1,s+m+1,cmp);
	for(long long i=1;i<=m;i++)
	{
		if(findf(s[i].u)==findf(s[i].v))
		{
			continue;
		}
		d++;
		qt[d].u=s[i].u;
		qt[d].v=s[i].v;
		qt[d].w=s[i].w;
		s[i].u=findf(s[i].u);
		s[i].v=findf(s[i].v);
		f[s[i].u]=s[i].v;
	}
	return;
}
void krks()
{
	long long d=0,nm=n-1,dn=0;
	for(long long i=1;i<=nm;i++)
	{
		vt[i].u=qt[i].u;
		vt[i].v=qt[i].v;
		vt[i].w=qt[i].w;
	}
	for(long long i=1;i<=k;i++)
	{
		if(b[i]==false)
		{
			d++;
			continue;
		}
		dn+=a[i][0];
		for(long long j=1;j<=n;j++)
		{
			nm++;
			vt[nm].u=n+i;
			vt[nm].v=j;
			vt[nm].w=a[i][j];
		} 
	}
	for(long long i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	sort(vt+1,vt+nm+1,cmp);
	for(long long i=1;i<=nm;i++)
	{
		vt[i].u=findf(vt[i].u);
		vt[i].v=findf(vt[i].v);
		if(vt[i].u==vt[i].v)
		{
			continue;
		}
		f[vt[i].u]=vt[i].v;
		d++;
		dn+=vt[i].w;
		if(d==n+k-1)
		{
			break;
		}
	}
	mn=min(mn,dn);
	return;
}
void ddfs(long long i)
{
	if(i==k+1)
	{
		krks();
		return;
	}
	b[i]=true;
	ddfs(i+1);
	b[i]=false;
	ddfs(i+1);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	krksx();
	for(long long i=1;i<=k;i++)
	{
		for(long long j=0;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	ddfs(1);
	cout<<mn;
	return 0;
}
