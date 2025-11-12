#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read () {
	ll X = 0;bool O = false;char C = getchar();
	while (!(C >= '0' && C <= '9')) O ^= (C=='-'), C = getchar();
	while (C >= '0' && C <= '9') X = (X << 3) + (X << 1) + (C - '0'), C = getchar();
	if (O) X = -X;
	return X;
}
const int MAXN = 5e5 + 10;
int A[MAXN];
// 大概100/20*12=60分吧 这太难了QAQ 
// 暴力分都快吃不上了呜呜呜 
struct co{
	int L, R;
	friend operator < (co A, co B) {
		return A.R - A.L + 1 > B.R - B.L + 1;
	}
};
priority_queue<co> Q;
int main () {
	// std::cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int N, K, Ans = 0, i = 0, j = 0, Temp = 0;
	N = read(), K = read();
	// cin >> N >> K;
	for (int i = 0; i < N; i++) {
		A[i] = read();
		// cin >> A[i];
	}
	if (K == 0) {
		i = j = 1;
		Temp = A[0];
	}
	int cnt = 0;
	while (i < N) {
		while (j < N) {
			Temp ^= A[j++];
			if (Temp == K) {
				Q.push({i, j - 1});
				cnt++;
			}
		}
		i++, j = i, Temp = 0;
	}
//	int xnt = 0;
//	while (!Q.empty()) {
//		cout << xnt++ << " " << Q.top().L << " " << Q.top().R << '\n';
//		Q.pop();
//	}
	// 那么如何找到互不干扰的呢？？？ 
	vector<bool> P(N);
	while (!Q.empty()) {
		co Z = Q.top();Q.pop();
		bool cont = false;
		for (int j = Z.L; j <= Z.R; j++) {
			if (P[j]) {
				cont = true;
				break;
			}
		}
		if (cont) continue;
		for (int j = Z.L; j <= Z.R; j++) {
			P[j] = true;
		}
		Ans++;
		// cout << Ans << " " << Z.L << " " << Z.R << '\n';
	}
	cout << Ans;
	// 额样例6花了40s结果答案还是错的，不管了 
	return 0;
} 
//int main () {
//	std::cin.tie(nullptr) -> sync_with_stdio(false);
//	freopen("xor4.in", "r", stdin);
//	int N, K, Ans = 0, i = 0, j = 0, Temp = 0;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		cin >> A[i];
//	}
//	if (K == 0) {
//		i = j = 1;
//		Temp = A[0];
//	}
//	while (j < N) {
//		while (j < N && Temp != K) {
//			Temp ^= A[j++];
//		}
//		if (Temp == K) {
//			cout << i << ' ' << j << ' ';
//			Ans++;
//			cout << Ans << endl;
//			i = j, Temp = 0;
//		}
//	}
//	cout << Ans;
//	return 0;
//} 
/*
可以先求出哪些l, r内异或和为k
然后选最小的依次排除掉其他的（即优先选最小，贪心）
这应该是可行的吧？
那么如何求出l, r内异或为k的？
我的想法是以i为起点i = [0, n - 1]
然后while j 扩张？那不还是一样的吗，更何况如何做到区间不交叉？我想到的只有双指针了
烷基八蛋了啊啊啊啊啊啊啊啊啊啊
双指针，选最小，我选啥啊啊啊 
其实这是人机写的代码，因为写代码时屏幕前的那个人比人机还人机写不出入门及以上的代码口牙 
我要回家啊啊啊啊我要回家啊啊啊啊啊啊啊啊啊啊啊啊啊啊
好的，再BBQ一下，可以看到N = [1, 5e5], 所以最终时间复杂度应该在O(NlogN)范围内
不然就limit time = 1.0s 超78时了 
可以看到可以通过特殊性质A, B 
说明能拿一半分……吧？
那最终成绩250分我也拿不到一等奖啊啊啊啊啊啊啊啊啊啊啊
kdjfsagksjdfgksjdgfkasdgf
摆烂了，果然我就是个纯纯的废物蒟蒻，哎 
*/
