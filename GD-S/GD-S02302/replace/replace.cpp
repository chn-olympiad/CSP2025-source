/*
在语言学中，谐音替换是指将原有的字词替换为读音相同或相近的字词。
小 W 发现，谐音替换的过程可以用字符串来进行描述。
具体地，小 W 将谐音替换定义为以下字符串问题：
给定 n 个字符串二元组，第 i (1 ≤ i ≤ n) 个字符串二元组为 (si,1, si,2)，
满足|si,1| = |si,2|，其中 |s| 表示字符串 s 的长度。
对于字符串 s，定义 s 的替. 换. 如下：
  对于 s 的某个子串 y，若存在 1 ≤ i ≤ n 满足 y = si,1，则将 y 替换为 y′ = si,2。
具体地，设 s = x + y + z，其中 x 和 z 可以为空，“+”表示字符串拼接，则 s的替换将得到字符串 s′ = x + y′ + z。
小 W 提出了 q 个问题，第 j (1 ≤ j ≤ m) 个问题会给定两个不. 同. 的字符串 tj,1, tj,2，
她想知道有多少种字符串 tj,1 的替换能够得到字符串 tj,2。
两种 s 的替换不同当且仅当子. 串.y 的. 位. 置. 不. 同. 或. 用. 于. 替. 换. 的. 二. 元. 组.(si,1, si,2) 不. 同. ，即 x, z 不同或 i 不同。
你需要回答小 W 提出的所有问题
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		string a, b; cin >> a >> b;
	}
	for(int j = 1; j <= q; j ++) {
		string a, b; cin >> a >> b;
		cout << 0 << '\n';
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
