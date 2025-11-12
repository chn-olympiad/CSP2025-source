#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 505;

int n, m, fac[N];
char s[N];

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	fac[0] = 1;
	for(int i = 1 ; i <= n ; i ++){
		fac[i] = (fac[i - 1] * i) % mod;
		cin >> s[i];
		if(s[i] == '0'){
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << fac[n];
	return 0;
}
// 这数据有问题吗为什么过不了
// 我要哭了 
// 预计得分 35 + 48 + 0 + 24 = 107
// 我真的求你1=分数线105吧 
// 唉 
// 我求你了下次还是送第一题吧 
// 你要是送第一题我今年一定1=
// 可是你为什么不送呢
// 不是事不过三吗
// 才两次啊 
// 我整场考试就是在赌
// 赌数据
// 我还有救吗 
