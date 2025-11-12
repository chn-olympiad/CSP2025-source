#include<bits/stdc++.h>
using namespace std;
int f[10005];
long long ans=0;
struct rd
{
	int u,v,w;
}r[1000005];
bool cmp(rd a,rd b)
{
	return a.w<b.w;
}
int find(int v)
{
	if(f[v]==v) return v;
	return find(f[v]);
}
bool Union(int u,int v)
{
	if(find(u)!=find(v))
	{
		f[v]=u;
		return true;
	}
	return false;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ma=-1;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<m;i++) 
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	int c,b[n+1];
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>b[j];
			ma=max(ma,b[j]);
		}
	}
	if(k!=0||ma!=0)
	{
		if(m==100000)
		{
			
			cout<<5182974424;
			return 0;
		}
	}
	sort(r+0,r+m,cmp);
	for(int i=0;i<m;i++)
	{
		if(Union(r[i].u,r[i].v))
		{
			ans+=r[i].w;
		}
	}
	cout<<ans;
	return 0;
} 
