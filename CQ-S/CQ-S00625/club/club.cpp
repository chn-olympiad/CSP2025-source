#include <bits/stdc++.h>

#ifndef CRT
#define endl '\n'
#endif

using namespace std ;

typedef long long ll ;
typedef unsigned long long ull ;
typedef long double ld ;

const ll N = 2e5 + 5 ;

ll T , n , a [N] [3] ;

ll choose [N] ;

void solve () 
{
	cin >> n ;
	for ( ll i = 1 ; i <= n ; i ++ )
	{
		for ( ll j = 1 ; j <= 3 ; j ++ )
		{
			cin >> a [i] [j] ;
		}
	}
	ll cnt1 = 0 , cnt2 = 0 , cnt3 = 0 ;
//	vector <ll> v1 , v2 , v3 ;
	ll ans = 0 ;
	priority_queue <pair <ll,ll>,vector <pair <ll,ll>>,less <pair <ll,ll>>> c1 , c2 , c3 ;
	for ( ll i = 1 ; i <= n ; i ++ )
	{
		if ( max ( { a [i] [1] , a [i] [2] , a [i] [3] } ) == a [i] [1] )
		{
//			v1.emplace_back ( i ) ;
			cnt1 ++ ;
//			q2.emplace ( a [i] [2] - a [i] [1] , i ) ;
//			q3.emplace ( a [i] [3] - a [i] [1] , i ) ;
			c1.emplace ( max ( a [i] [3] - a [i] [1] , a [i] [2] - a [i] [1] ) , i ) ;
//			cerr << 1 << endl ;
		}
		else if ( max ( { a [i] [1] , a [i] [2] , a [i] [3] } ) == a [i] [2] )
		{
//			v2.emplace_back ( i ) ;
			cnt2 ++ ;
//			q1.emplace ( a [i] [1] - a [i] [2] , i ) ;
//			q3.emplace ( a [i] [3] - a [i] [2] , i ) ;
			c2.emplace ( max ( a [i] [1] - a [i] [2] , a [i] [3] - a [i] [2] ) , i ) ;
//			cerr << 2 << endl ;
		}
		else
		{
//			v3.emplace_back ( i ) ;
			cnt3 ++ ;
//			q1.emplace ( a [i] [1] - a [i] [3] , i ) ;
//			q2.emplace ( a [i] [2] - a [i] [3] , i ) ;
			c3.emplace ( max ( a [i] [1] - a [i] [3] , a [i] [2] - a [i] [3] ) , i ) ;
//			cerr << 3 << endl ;
		}
		ans += max ( { a [i] [1] , a [i] [2] , a [i] [3] } ) ;
	}
//	if ( v1.size () > n / 2 )
//	{
		while ( cnt1 > n / 2 )
		{
			ans += c1.top ().first ;
			c1.pop () ;
//			v1.pop_back () ;
			cnt1 -- ;
		}
//	}
	while ( cnt2 > n / 2 )
	{
		ans += c2.top ().first ;
		c2.pop () ;
//		v2.pop_back () ;
		cnt2 -- ;
	}
	while ( cnt3 > n / 2 )
	{
		ans += c3.top ().first ;
		c3.pop () ;
//		v3.pop_back () ;
		cnt3 -- ;
	}
	cout << ans << endl ;
}

signed main ()
{
//#if not defined ( CRCC )
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ;
//#endif 
	ios::sync_with_stdio ( 0 ) ;
	cin.tie ( 0 ) ;
	cout.tie ( 0 ) ;
	cin >> T ;
	while ( T -- )
	{
		solve () ;
	}
	return 0 ;
}
/*
游记：

这场打不好就退役了/ng

这个 T1 看着很反悔贪心。

考虑全部优先选同一组。

欸写了 40min 怎么还炸了。

彻底怒了。

欸注意到优先选当前最大的那一组，然后最多只有一组超了，这时反悔贪心即可。

写了 20min 才过。

完了 1h 过 T1，这场没救了。/fad

T2 注意到有一种枚举哪些乡镇需要城镇化的做法。我会 48pts。

额让我烧烤。注意到乡镇是不能和乡镇连边的，这启发我们对每个乡镇分开思考。

让我们想想每个乡镇会对最小生成树带来什么。

首先如果城市化了某个乡镇，这个乡镇也会被加入点集中，不然显然不优。

其次这个乡镇至少连了两条边。某一端是乡镇的边中，任意两条连接的两点，其经过乡镇的边权和小于经过原最小生成树的边权和。

还有什么性质呢，不会了。

还是先打暴力吧。

？不是哥们怎么跑这么慢。不是只有 $O(2^km\log m)$ 吗。

我有一个好方法，对每个城镇的边排序之后做归并。

跑的更慢了/fad

欸原来我会性质啊。不就是所有边全部丢进去吗。

现在我会 56 分了。

先跳了换 T3 吧。

T3 半个小时搓了个暴力/fad

还能干啥。现在是 17:36。

继续冲 T2。

2.9s。烂完了。

别跟我说正解是可持久化并查集。

给 T4 骗分。

首先是暴力。

然后 m == n 的是显然的。

不会了/fad

现在才 191 怎么办。

彻底似了。

我就知道这场会炸。

陨落了。这应该是最后一次正式赛了。

以后说不定还会上洛谷看看。uid 700210，可以来找我玩。
*/
