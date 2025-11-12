#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct road1
{
	int u,v,w;
};
road1 r1[1000011];
struct road2
{
	int c;
	int a[10011];
};
road2 r2[11];
int n,m,k;
int ans = 0;

int f[10001];
int find(int x)
{
	if(f[x] == x)
		return x;
	else
		find(f[x]);
}
void hb(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	
	if(fx != fy)
		f[fy] = f[fx];
}
bool com(road1 x,road1 y)
{
	return x.w < y.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++) f[i] = i;
	for(int i = 1;i <= m;i++)
	{
		cin>>r1[i].u>>r1[i].v>>r1[i].w;
	}
	for(int i = 1;i <= k;i++)
	{
		cin>>r2[i].c;
		for(int j = 1;j <= n;j++)
			cin>>r2[i].a[j];
	}
	
	
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			r1[i+m].u = i+n;
			r1[i+m].v = j;
			r1[i+m].w = r2[i].c + r2[i].a[j];
		}
	}
	
	sort(r1+1,r1+m+k+1,com);//
	
	for(int i = 1;i <= n+k-1;i++)
	{
		if(find(r1[i].u) != find(r1[i].v))
		{
			hb(r1[i].u,r1[i].v);
			ans += r1[i].w;
			
		}
		
	}
	cout<<ans;
	
	return 0;
}
