#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10007];
int v[10007];
int w[10007];
int c[10007][10007];
int cnt;
int a[10007];
long long dis[10007];
deque<int> q;
long long total = 0;

void init()
{
	for(int i = 1; i <= 10000 ; i++)
	{
		dis[i] = 100000000000;
	}
}
void dij()
{
	int o;
	while(!q.empty())
	{
		o = q.front();
		q.pop_front();
		for(int i = 1; i <= m; i++)
		{
			if((v[i] == o or u[i] == o) and dis[i] > dis[o] + w[i])
			{
				dis[i] = dis[o] + w[i];
				q.push_back(i);
			}
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	init();
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		if(u[i] == 1 or v[i] == 1)
		{
			q.push_front(i);
		}
	}
	dis[1] = 0;
	for(int i = 1; i <= k; i++)
	{
		cnt = 0;
		for(int j = 0; j <= k;j++)
		{
			scanf("%d",&c[i][j]);
			if(j != 0 and c[i][j] == 0)
			{
				a[++cnt] = j;
			}
			if(j != 0)
			{
				w[j] = min(c[i][j] + c[i][0],w[j]);
			}
		}
		for(int j = 1; j <= cnt ; j++)
		{
			for(int kk = 1; kk <= m;k++)
			{
				w[kk] = min(c[i][a[cnt]],w[kk]);
			}
		}
	}
	dij();
	for(int i = 1; i <= n; i++)
	{
		if(dis[i] != 100000000000)
		{
			total = max(total,dis[i]);
		}
	}
	printf("%lld",total);
}
