#include <bits/stdc++.h>
using namespace std;
int n, m, k, fa[100020];
long long anss = 1e18;

struct node{
	long long u, v, w;
}g[3000005];
bool cmp(node x, node y)
{
	return x.w < y.w;
}
int findfa(int x)
{
	if(x==fa[x]) return x;
	return fa[x] = findfa(fa[x]);
}
void KK(int N, int M, long long st)
{
	long long cnt = 0, ans = st;
	for(int i = 1; i <= M; i++)
	{
		int x = findfa(g[i].u), y = findfa(g[i].v);
		if(x==y) continue;
		fa[x] = y;
		ans += g[i].w;
		cnt++;
	//	cout << i << " " <<x<<" "<<y<<" "<< ans << "\n";
		if(cnt == N - 1)
		{
		//	cout << ans << "\n";
			anss = min(ans,anss);
			return;
		}
	}
}
long long dis[15][10005], co[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= n+k; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
		scanf("%lld%lld%lld",&g[i].u,&g[i].v,&g[i].w);
	bool flag = true;
	for(int i = 1; i <= k; i++)
	{
		scanf("%lld",&co[i]);
		if(co[i]!=0) flag = false;
		for(int j = 1; j <= n; j++)
		{
			scanf("%lld",&dis[i][j]);
		}
	}
	if(flag == true)
	{
		for(int i = 1; i <= k; i++)
		{
			scanf("%lld",&co[i]);
			//if(co[i]!=0) flag = false;
			for(int j = 1; j <= n; j++)
			{
				g[++m].u = n+i, g[m].v = j, g[m].w = dis[i][j];
			}
		}
		sort(g+1,g+1+m,cmp);
		KK(n+k,m,0);
		printf("%lld",anss);
		return 0;
	}
	int cntnew = 0;
	if(k==0)
	{
		sort(g+1,g+1+m,cmp);
		KK(n,m,0);
		printf("%lld",anss);
	}else if(k==1)
	{
		sort(g+1,g+1+m,cmp);
		KK(n,m,0);
		
		for(int i = 1; i <= n+k; i++) fa[i] = i;
		for(int i = 1; i <= n; i++)
			cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = i, g[m+cntnew].w = dis[1][i];
		sort(g+1,g+1+m+n,cmp);
		KK(n+1,m+n,co[1]);
		printf("%lld",anss);
	}else if(k==2)
	{
		sort(g+1,g+1+m,cmp);
		KK(n,m,0);
		
		for(int i = 1; i <= n+k; i++) fa[i] = i;
		for(int i = 1; i <= n; i++)
			cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = i, g[m+cntnew].w = dis[1][i];
		sort(g+1,g+1+m+n,cmp);
		KK(n+1,m+n,co[1]);
		
		for(int i = 1; i <= n+k; i++) fa[i] = i;
		cntnew = 0;
			for(int i = 1; i <= n; i++)
			cntnew++, g[m+cntnew].u = n+2, g[m+cntnew].v = i, g[m+cntnew].w = dis[2][i];
		sort(g+1,g+1+m+n,cmp);
		KK(n+1,m+n,co[2]);
		
		for(int i = 1; i <= n+k; i++) fa[i] = i;
		for(int i = 1; i <= n; i++)
			cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = i, g[m+cntnew].w = dis[1][i];
		sort(g+1,g+1+m+n*2,cmp);
		KK(n+2,m+n*2,co[1]+co[2]);
		printf("%lld",anss);
	}else if(k>=3)
	{
		sort(g+1,g+1+m,cmp);
		KK(n,m,0);
		
		for(int i = 1; i <= n+k; i++) fa[i] = i;
		for(int i = 1; i <= k; i++) 
		{
			for(int j = 1; j <= n+k; j++) fa[j] = j;
			cntnew = 0;
			for(int j = 1; j <= n; j++)
				cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = j, g[m+cntnew].w = dis[i][j];
			sort(g+1,g+1+m+n,cmp);
			KK(n+1,m+n,co[i]);
		}
		for(int i = 1; i <= k-1; i++)
		{
			for(int j = i+1; j <= k; j++)
			{
				if(co[i]+co[j]>anss) continue;
				for(int l = 1; l <= n+k; l++) fa[l] = l;
				cntnew = 0;
				for(int l = 1; l <= n; l++)
					cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = l, g[m+cntnew].w = dis[i][l];
				for(int l = 1; l <= n; l++)
					cntnew++, g[m+cntnew].u = n+2, g[m+cntnew].v = l, g[m+cntnew].w = dis[j][l];
				sort(g+1,g+1+m+n*2,cmp);
				KK(n+2,m+n*2,co[i]+co[j]);
			}
		}
		if(k==3)
		{
			for(int i = 1; i <= n+k; i++) fa[i] = i;
			for(int i = 1; i <= n; i++)
			cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = i, g[m+cntnew].w = dis[1][i];
			sort(g+1,g+1+m+n*3,cmp);
			KK(n+3,m+n*3,co[1]+co[2]+co[3]);
		}else if(k>=4)
		{
			for(int i = 1; i <= k-2; i++)
			{
				for(int j = i+1; j <= k-1; j++)
				{
					for(int l = j+1; l <= k; l++)
					{
						if(co[i] + co[j] + co[l] > anss) continue;
						for(int o = 1; o <= n+k; l++) fa[o] = o;
						cntnew = 0;
						for(int o = 1; o <= n; o++)
							cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = o, g[m+cntnew].w = dis[i][o];
						for(int o = 1; o <= n; o++)
							cntnew++, g[m+cntnew].u = n+2, g[m+cntnew].v = o, g[m+cntnew].w = dis[j][o];
						for(int o = 1; o <= n; o++)
							cntnew++, g[m+cntnew].u = n+3, g[m+cntnew].v = o, g[m+cntnew].w = dis[l][o];
						sort(g+1,g+1+m+n*3,cmp);
						KK(n+3,m+n*3,co[i]+co[j]+co[l]);
					}
				}
			}
			if(k==4)
			{
				for(int i = 1; i <= n+k; i++) fa[i] = i;
				for(int i = 1; i <= n; i++)
				cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = i, g[m+cntnew].w = dis[1][i];
				sort(g+1,g+1+m+n*4,cmp);
				KK(n+4,m+n*4,co[1]+co[2]+co[3]+co[4]);
			}else{
				for(int i = 1; i <= k-3; i++)
				{
					for(int j = i+1; j <= k-2; j++)
					{
						for(int l = j+1; l <= k-1; l++)
						{
							for(int o = l+1; o <= k; o++)
							{
								if(co[i]+co[j]+co[l]+co[o] > anss) continue;
								for(int p = 1; p <= n+k; l++) fa[o] = o;
								cntnew = 0;
								for(int p = 1; p <= n; p++)
									cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = p, g[m+cntnew].w = dis[i][p];
								for(int p = 1; p <= n; p++)
									cntnew++, g[m+cntnew].u = n+2, g[m+cntnew].v = p, g[m+cntnew].w = dis[j][p];
								for(int p = 1; p <= n; p++)
									cntnew++, g[m+cntnew].u = n+3, g[m+cntnew].v = p, g[m+cntnew].w = dis[l][p];
								for(int p = 1; p <= n; p++)
									cntnew++, g[m+cntnew].u = n+4, g[m+cntnew].v = p, g[m+cntnew].w = dis[o][p];
								sort(g+1,g+1+m+n*4,cmp);
								KK(n+4,m+n*4,co[i]+co[j]+co[l]+co[o]);
							}
						}
					}
				}
				for(int i = 1; i <= n+k; i++) fa[i] = i;
				for(int i = 1; i <= n; i++)
				cntnew++, g[m+cntnew].u = n+1, g[m+cntnew].v = i, g[m+cntnew].w = dis[1][i];
				sort(g+1,g+1+m+n*5,cmp);
				KK(n+5,m+n*5,co[1]+co[2]+co[3]+co[4]+co[5]);
			}
		}
		printf("%lld",anss);
	}
	return 0;
}
 
