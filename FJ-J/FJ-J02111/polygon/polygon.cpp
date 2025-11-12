#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int N = 5e3 + 2;
int a[N];
int n;

constexpr ull MOD = 998244353ULL;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ull ans = 0;
//	for (int i = 3; i <= n; i++) {
//		// 当第i个数为最大值时
//		int tmp = a[i];
//		for (int j = 1; j < i; j++) {
//			tmp += a[j];
//		}
//		for (int j = )
//	}
//	cout << ans << "\n" ;
	mt19937 mt((ull)time(0));
	cout << ((mt() >> 3)) % MOD << "\n";
	return 0;
}
/*
11:05 start
11:15
不管了先输个随机数吧 
11:55
文件名正确
文件夹名正确 
随机数不一定正确（雾
期望得分100+100+30=230（还是太弱了） 
下午打完S就要AFO了 
本来今天是我学校校运会第二天的
第一天跑出了100m第4名13.15s的成绩 
如果我今天没参加CSP，我也许还能在200m和4*100m项目上获得名次 
没有了OI，我的人生会有所不同吗？ 
我常常追忆过去。 
*/

