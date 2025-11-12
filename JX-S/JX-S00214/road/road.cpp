#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u[1000001],v[1000001];
long long w[1000001];
long long c[11];
long long a[11][10001];
int fa[100001];

void build()
{
	for(int i = 1;i <= n;i++)
	{
		fa[i] = i;
	}
}

int get(int x)
{
	if(x == fa[x]){return x;}
	return fa[x] = get(fa[x]);
}

void merge(int x,int y)
{
	if(get(x) == get(y))
	{return;}
	fa[get(x)] = get(y);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j = 1;j <= k;j++)
	{
		cin >> c[j];
		for(int i = 1;i <= n;i++)
		{
			cin >> a[j][i];
		}
	}
	long long ans = 0;
	for(int i = 1;i <= m;i++)
	{
		ans += w[i];
	}
	cout << ans;
	return 0;
}
