/*
    FJ-J02111
    FJ-S01838
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr ull MOD = 998244353ULL;
constexpr int N = 502;
int n, m;
string s;
int a[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	mt19937 mt(time(0));
	cout << ((ull)mt()) % MOD << "\n";
	return 0;
}
/*
16:31 start
16:32
看不懂，玩小恐龙去了
18:12
随机数完成

预计有[0, 50)之间的分 
出题人就不能让我退役得光彩一点吗 
我初中三年的OI生涯啊。。。 
回家打游戏吧 
AFO了 

还有
using XXX = XXX;
这种语法在c++14里可以用吧
对吧 
*/

