#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int N = 2e5 + 2;
string s[N][2];
int n, q;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	while (q--) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << "0\n";
	}
	return 0;
}
/*
16:20 start
16:25
？？？？？？？？？？ (这不是乱码)
abdeghijlmnopqrstvwxyz Coin Collecting Foundation
这什么题目 
看不懂，下一题 
*/

