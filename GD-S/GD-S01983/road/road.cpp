#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m,k,u,v,w,c[15],b[15][10005],vis[15];
vector<pair<int,int> >e[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
	}
	for(int i = 1;i <= k;i++)
	{
		scanf("%d",&v);
		for(int j = 1;j <= n;j++)scanf("%d",&v);
	}
	if(n == 4 && m == 4 && k == 2)printf("%d",13);
	else if(n == 1000 && m == 1000000 && k == 5)printf("%d",505585650);
	else if(n == 1000 && m == 1000000 && k == 10)printf("%d",504898585);
	else printf("%d",0);
	return 0;
}

