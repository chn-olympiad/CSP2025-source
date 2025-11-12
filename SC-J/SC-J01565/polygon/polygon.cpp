#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 5e3 + 5;
int dp[2][N];
int a[N], n, Ans;
int ksm(int x){
	if(!x)return 1ll;
	int ins = ksm(x >> 1);
	if(x & 1)return ins * ins % mod * 2ll % mod;
	return ins * ins % mod;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	Ans = ksm(n) - 1ll;
	for(int i = 1; i <= n; i++){
		for(int k = 0; k < a[i]; k++)dp[i & 1][k] = dp[(i - 1) & 1][k];
		for(int k = a[i]; k <= 5000; k++)dp[i & 1][k] = (dp[(i - 1) & 1][k] + dp[(i - 1) & 1][k - a[i]]) % mod;
		int remain = 0;
		for(int k = 1; k <= a[i]; k++)remain = (remain + dp[i & 1][k]) % mod;
		Ans = (Ans - remain + mod) % mod;
	}
	cout << Ans << endl;
	return 0;
}
/*
Note

2025-11-1 9:30 Pass T4
AK CSP-J.Final

Solution
明显直接排序后钦定最大值进行统计
显然的，如果统计sum > max一类的情况数是不好做的
注意到 ai <= 5000，考虑正难则反，统计sum < max的情况数
采用二维dp转移，第一位用滚动数组压掉即可，O(nlogn + nV)

Note

2025-11-1 9:45
严格简单于去年的J组T4，怎么T3, T4都是dp，希望S组不要考数学，并不有意思
还有2h，怎么办怎么办，玩一会冲浪去 

2025-11-1 9:48
不想玩了，对拍一下 

2025-11-1 10:03
对拍完了，没有什么问题，又无聊了 

2025-11-1 11:19
玩了5种纸牌，都过了，不好玩了，再检查一下代码 

2025-11-1 11:24
星野星野星野星野星野星野，卡哇伊捏，星野哦，不过DMY更好看捏=) 

2025-11-1 11:30
不写了，交了交了，祝愿S组rp++，Luogu Account:Arrtan_73，欢迎壶关，前提是私信我一下，不然不知道呢喵~ 
*/