// T1 AC
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
inline ll read()
{
	ll x = 0,f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-'? -1 : f),c = getchar();
	while(c >= '0' && c <= '9') x = (x<<1) + (x<<3) + c - '0',c = getchar();
	return x * f;
}

ll n; pair<ll,ll> a[N][5];
vector<int> g[5];

void solve()
{
	n = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 3; j++)
			a[i][j].first = read(),a[i][j].second = j;
	
	for(int i = 1; i <= n; i++) sort(a[i] + 1,a[i] + 4,greater<pair<ll,ll> >());
	ll ans = 0;
	for(int id = 1; id <= 3; id++) g[id].clear();
	for(int i = 1; i <= n; i++) ans += a[i][1].first,g[a[i][1].second].push_back(i);
	for(int id = 1; id <= 3; id++) if(g[id].size() > n / 2)
	{
		vector<ll> l;
		for(int i : g[id]) l.push_back(a[i][1].first - a[i][2].first);
		sort(l.begin(),l.end());
		for(int i = 0; i < g[id].size() - n / 2; i++) ans -= l[i];
		break;
	}
	printf("%lld\n",ans);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T = read();
	while(T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

