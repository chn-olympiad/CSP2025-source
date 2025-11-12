#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(x, y, z) for(ll x = y; x <= z; x++)
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 1e4 + 20, M = 1e6 + 10, K = 11;
ll n, m, k;
//vector<pair<ll, ll>> h[N];
array<ll, 3> g[M];

ll fa[N];
ll fifa(ll x)
{
	if(fa[x] == x) return x;
	return fa[x] = fifa(fa[x]);
}
vector<array<ll, 3>> a; // 原图
vector<array<ll, 3>> kb[K]; // 前半段
vector<array<ll, 3>> b[(1ll << 6) + 10]; // 后半段
ll c[K]; // !!!
ll mk(ll x)
{
	return 1ll << (x - 1);
}

ll mst[(1ll << 6) + 10];
signed main()
{
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	f(i, 1, m)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		g[i] = {z, x, y};
	}
	sort(g + 1, g + m + 1);
	f(i, 1, n) fa[i] = i;
	f(i, 1, m)
	{
		ll x = g[i][1], y = g[i][2], z = g[i][0];
		if(fifa(x) == fifa(y)) continue;
		a.push_back(g[i]);
		fa[fifa(x)] = fifa(y);
	}
	f(i, 1, k) // k = 0!
	{
		cin >> c[i];
		f(j, 1, n)
		{
			ll x;
			cin >> x;
			if(i <= 5) kb[i].push_back({x, n + i, j});
			else b[mk(i)].push_back({x, n + i, j});
		}
	}

	f(i, 1, mk(max(0ll, k - 5) + 1) - 1)
	{
//	cerr<<i<<endl;
		f(j, 1, k - 5) if(mk(j) & i) mst[i] += c[j];
		f(j, 1, k - 5) if(mk(j) & i)
		{
			if(i == mk(j)) break;
			b[i] = b[i ^ mk(j)];
			for(auto x : b[mk(j)]) b[i].push_back(x); //
			break;
		}
		sort(b[i].begin(), b[i].end());
	}
//	cerr<<114<<endl;

	ll ans = INF;
	f(i, 0, mk(min(5ll, k) + 1) - 1)
	{
		ll moe = 0;
		vector<array<ll, 3>> t;
		f(j, 1, min(5ll, k)) if(i & mk(j))
		{
			for(auto x : kb[j]) t.push_back(x);    //
			moe += c[j];
		}

		for(auto x : a) t.push_back(x); //
		sort(t.begin(), t.end());

//		ll _i = i;
		f(i, 0, mk(max(0ll, k - 5) + 1) - 1)
		{
			ll res = mst[i] + moe;
			vector<array<ll, 3>> e = t;
			for(auto x : b[i]) e.push_back(x);
			sort(e.begin(), e.end());
			f(i, 1, n + k) fa[i] = i;
//			cerr<<res<<"   aaa"<<endl;
			for(auto it : e)
			{
				ll x = it[1], y = it[2], z = it[0];
				if(fifa(x) == fifa(y)) continue;
				fa[fifa(x)] = fifa(y);
				res += z;
			}
			if(0 && res == 12)
			{
				for(auto it : e)
				{
					ll x = it[1], y = it[2], z = it[0];
					cerr << x << " " << y << " " << z << endl;
				}
			}
//			cerr<<114<<endl;
//			if(res == 12) cerr<<_i<<" "<<i<<endl;
			ans = min(ans, res);
		}
	}
	cout << ans << endl;
	return 0;
}
/*
k = 0 的话就是最小生成树

考虑有效的边

猜想也是最小生成树上的

尝试反证

先考虑 k = 1

不用了

直接考虑终态，若存在

反正随便证

先把原树找出来

边权排好序

指数的复杂度枚举点的修改情况。

然后归并上新的这些边

再扫一遍

复杂度 nlogm + klogn + 2^k * k * (n + n)

15:31

感觉复杂度不太对啊，少算了个 k

每次合并

考虑可不可以预处理2 ^ k的方案下的最小生成树

然后合并？

可以先处理 k 的前 8 个

不了

直接折半吧

那就做完了

直接 300

16：24
*/
