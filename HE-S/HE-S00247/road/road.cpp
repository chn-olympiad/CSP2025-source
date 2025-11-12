#include<bits/stdc++.h>
using namespace std;
struct dfs{
	int a,b,c;
}a[10001];
struct dfss{
	int f,x,y,z,nm;
}b[10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=0,m=0,k=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	for(int i=1;i<=k;++i)
	{
		cin>>b[i].f>>b[i].x>>b[i].y>>b[i].z>>b[i].nm;
	}
	return 0;
}
