#include<bits/stdc++.h>
using namespace std;
struct road
{
	int u, v;
	long long w;
};
bool cmp(road x, road y)
{
	return x.w<y.w;
}
vector<int> fa;
vector<road> tu;
vector<long long> a; 
int ans=0;
int fr(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=fr(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, m, k;
    cin >> n >> m >> k;
	road x;
    for(int i=1;i<=m;i++)
    {
		cin >> x.u >> x.v >> x.w;
		tu.push_back(x);
	}
	if(n<10000)
	{
		a.resize(n+5);
		while(k--)
		{
			long long c;
			cin >> c;
			for(int i=1;i<=n;i++)
			{
				cin >> a[i];
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					tu.push_back({i,j,c+a[i]+a[j]});
				}
			}
		}
	}
	sort(tu.begin(),tu.end(),cmp);
	fa.resize(n+5);
	ans=n;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int id=-1;
	long long sum=0;
	while(ans!=1)
	{
		id++;
		int u=tu[id].u, v=tu[id].v;
		long long w=tu[id].w;
		int fu=fr(u), fv=fr(v);
		if(fu!=fv)
		{
			sum+=w;
			fa[fu]=fv;
			ans--;
		}
	}
	cout << sum;
    return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
