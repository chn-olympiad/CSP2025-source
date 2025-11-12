#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Tcs
{
	int u,v,w;
}tcs[10010];
struct Tcz
{
	int j,w[10010];
}tcz[1000010];

int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >> k;
	for(int i=1;i<=m;i++)
	{
		cin >> tcs[i].u >> tcs[i].v >> tcs[i].w;
		
	}
	return 0;
}
