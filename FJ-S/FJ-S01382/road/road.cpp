#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e4+10;
struct edge
{
	long long u,v,w;
}a[N];
long long n,m,k,cnt,num,c[15];
int f[M];
bool cmp(edge a,edge b)
{
	if(a.w<b.w)
		return true;
	return false; 
}
int find(int x)
{
	if(f[x]==x)
		return x;
	return find(f[x]);
}
long long kruskal()
{
	for(int i=1;i<=m;++i)
	{
		int p=find(a[i].u);
		int q=find(a[i].v);
		if(q!=p)
		{
			f[p]=q;
			cnt++;
			num+=a[i].w;
		}
		if(cnt==n-1)
			return num;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=n;++i)
		f[i]=i;
	if(k==0)
	{
		sort(a+1,a+1+m,cmp);
		cout<<kruskal();
		return 0;
	}		
	return 0;
} 
