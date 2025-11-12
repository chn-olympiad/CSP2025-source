#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll N = 10005;
ll val[15];
struct node
{
	ll from, to, val;
}edg[2000005];
ll n, m, k;
vector<pair<ll,ll> > g[N];
void add(ll x, ll y, ll z)
{
	g[x].push_back(make_pair(y, z));
	g[y].push_back(make_pair(x, z));
}
bool cmp(node x, node y)
{
	return x.val < y.val;
}
ll fa[N + 50];
ll getfa(ll x)
{
	ll r=x, i;
	while(fa[r] != r)
		r = fa[r];
	while(fa[x] != r)
		i = fa[x], fa[x] = r, x = i;
	return r;
}
ll kruscal()
{
	sort(edg+1, edg+m+k*n+1, cmp);
	ll cnt = 0, res = 0, i, x, y;
	for(i = 1; i <= n + k; i++)
		fa[i] = i;
	for(ll i = 1; i <= m + k * n; i++)
	{
		x = getfa(edg[i].from);
		y = getfa(edg[i].to);
		if(x == y)
			continue;
		fa[x] = y;
		res += edg[i].val;
		add(edg[i].from, edg[i].to, edg[i].val);
		cnt++;
		if(cnt == n + k - 1)
        {
			return res;
        }
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll x, y, z, i, j, res;
	cin >> n >> m >> k;
	for(i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		edg[i] = (node){x, y, z};
	}
	for(i = 1; i <= k; i++)
	{
		cin >> val[i];
		for(j = 1; j <= n; j++)
		{
			cin >> y;
			edg[m + (i-1) * n + j] = (node){j, n + i, val[i] + y};
		}
	}
	res = kruscal();
	for(i = n + 1; i <= n + k; i++)
	{
		if(g[i].size() == 1)
		{
			res -= g[i][0].second;
		}
		else
		{
			res -= val[i - n] * (g[i].size() - 1);
		}
	}
	cout << res;
	fclose(stdin);
	fclose(stdout);
	return 0;
 }

