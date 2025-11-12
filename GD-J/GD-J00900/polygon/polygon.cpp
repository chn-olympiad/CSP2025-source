/*
我大抵是写完了题的
写一下考场游记：
其实没什么好写的，感觉这次的题没一个是比黄难的：
T1红
T2橙，排序后模拟即可（写对拍的时候没有给生成的数据去重，害得我找了5分钟问题（笑））
T3黄，注意到a^(a^k)=k。
首先记录一个异或和ji数组
开一个桶记录一下之前出现过的数字；当遇到ji_i时，查找是否存在(ji_i)^k，如果有那么答案加一，接着清空桶；然后记录这个数字
不能真的暴力清空，那样的话复杂度是O(nV)的，所以我的方案是不清空（
代码如下：
int ans = 1;
tong[0] = 1;
for (int i = 1; i <= n; ++i) {
	if (tong[ji[i] ^ k] == ans) ++ans;
	tong[ji[i]] = ans;
}
printf("%d", ans - 1);
类似于一个lazy_tag
也不知道对不对，题目给的大样例都过了，感觉是对的（如果我错了请不要笑我QAQ）
T4黄，dp_i表示用当前的棍母组成长度为i的组合数量
接着算一遍前缀和，然后ans+=qz[{可能的最大长度}]-qz[len[i]]（显然）
但！（猪猪语音包原子弹音）可能的最大长度可以到nV，如果每一次都真的算一遍那么复杂度是O(Vn^2)的
我们发现其实我们并不关心组成一个长度的方案，我们只需要知道组成比当前长度大的方案有多少
因此我们可以在超出最大值的地方这样更新：dp[V+1]+=qz[V+1]-qz[V-lens[i]]（显然）
然后不大于V的地方按照正常方式更新，这样复杂度就是O(nV)了
代码就在下面，只需要注意一些小细节就可以了
大概是这样的，应该是对的，没有考虑证明，题目给的大样例和自己手造的几组数据都过了
最后希望下午S考的也很好！
不过最近没怎么努力，因此考成大粪也是有可能的（哭）
如果下午S考好了的话那我大抵是可以继续OI生涯的了
最后祝所有OIer ++rp！！！
大家都能够AK IOI的！！！
考场游记：完（竟然写了34行）
*/
#include <bits/stdc++.h>
const int MOD = 998244353;
long long dp[5005], qz[5005];
int lens[5005];
int main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	dp[0] = qz[0] = 1;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", lens + i);
	std::sort(lens, lens + n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < 5005; ++j) qz[j] = (qz[j - 1] + dp[j]) % MOD;
		ans = (ans + qz[5001] - qz[lens[i]]) % MOD,
			dp[5001] = (dp[5001] + qz[5001] - qz[5000 - lens[i]]) % MOD;
		for (int j = 5000; j >= lens[i]; --j) dp[j] = (dp[j - lens[i]] + dp[j]) % MOD;
	}
	printf("%lld", ans);
}
