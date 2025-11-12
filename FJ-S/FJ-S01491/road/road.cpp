#include<bits/stdc++.h>
using namespace std;
const int _ =1e5+5;
int n,m,k,b[_][_];
struct road{
	int u,v,w;
}a[_];
void scan()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[i].u =u;
		a[i].v =v;
		a[i].w =w;
	}
	for(int j=1;j<=k;++j)
	{
		
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	scan();
	return 0;
}

