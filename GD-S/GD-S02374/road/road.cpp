#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u, v, w;
}a[7000005];
int c[10005];

int fa[10005], cst[20];

int find(int x)
{
	if(x==fa[x])
	return x;
	return fa[x]=find(fa[x]);
}

bool cmp(edge x,edge y)
{
	return x.w < y.w;
}

void merge(int x, int y)
{
	fa[find(x)]=find(y);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1; i <= n; i++)
		fa[i]=i;
	if(k==0)
	{
		long long sum = 0;
		sort(a+1,a+m+1,cmp);
		for(int i = 1; i <= m; i++)
		{
			if(find(a[i].u)==find(a[i].v))
			continue;
			merge(a[i].u,a[i].v);
			sum+=a[i].w;
		}
		cout << sum;
	}
	else
	{
		long long sum = 0, ans = 0, cnt = 0, x = 0;
		sort(a+1,a+m+1,cmp);
		for(int i = 1; i <= m; i++)
		{
			if(find(a[i].u)==find(a[i].v))
			continue;
			merge(a[i].u,a[i].v);
			sum+=a[i].w;
		}
		ans=sum;
		for(int i = 1; i <= k; i++)
		{
			cnt=0;
			fa[n+i]=n+i;
			cin >> cst[i];
			for(int j = 1; j <= n; j++)
				cin >> c[j];
			for(int l = 1; l < n; l++)
			{
				for(int j = l+1; j <= n; j++)
				{
					if(c[j]+c[l]>1e9)continue;
					cnt++;
					a[m+cnt]={i,j,c[j]+c[l]};
				}
			}
		}
		sort(a+1,a+m+cnt+1,cmp);
		for(int i = 1; i <= n; i++)fa[i]=i;
		sum = 0;
		for(int i = 1; i <= m+cnt; i++)
		{
			if(find(a[i].u)==find(a[i].v))
			continue;
			merge(a[i].u,a[i].v);
			sum+=a[i].w;
		}
		cout << sum << "\n";
	}
	//else
		//cout << 0;
	return 0;
}
