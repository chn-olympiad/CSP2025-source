#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull B = 29, mod = 10000000000000007ll, mod1 = 19999991ll;
const int L = 300;
int n, q;
vector<pair<int, pair<ull, ull>>> special;
map<pair<ull, ull>, int> cnt;
ull hsh[5000100], hsh1[5000100], powb[5000100];
ull get_hsh(int l, int r) {
	if (l > r) return 0;
	if (!l) return hsh[r];
	return hsh[r] - hsh[l - 1] * powb[r - l + 1];
}
ull get_hsh1(int l, int r) {
	if (l > r) return 0;
	if (!l) return hsh1[r];
	return hsh1[r] - hsh1[l - 1] * powb[r - l + 1];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	powb[0] = 1;
	for (int i = 1; i <= 5000000; i++) {
		powb[i] = powb[i - 1] * B % mod;
	}
	for (int i = 1; i <= n; i++) {
		string a, b;
		cin >> a >> b;
		ull hsh = 0;
		for (auto i : a) {
			hsh = (hsh * B + i - 'a' + 1) % mod;
		}
		ull hsh1 = 0;
		for (auto i : b) {
			hsh1 = (hsh1 * B + i - 'a' + 1) % mod;
		}
		if ((int)a.size() > L) {
			special.push_back({(int)a.size(), {hsh, hsh1}});
		}
		else {
			cnt[{hsh, hsh1}]++;
		}
	}
	while (q--) {
		string a, b;
		cin >> a >> b;
		hsh[0] = a[0] - 'a' + 1;
		for (int i = 1; i < (int)a.size(); i++) {
			hsh[i] = (hsh[i - 1] * B + a[i] - 'a' + 1) % mod;
		}
		hsh1[0] = b[0] - 'a' + 1;
		for (int i = 1; i < (int)b.size(); i++) {
			hsh1[i] = (hsh1[i - 1] * B + b[i] - 'a' + 1) % mod;
		}
		int ans = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			if (get_hsh(0, i - 1) != get_hsh1(0, i - 1)) continue;
			for (int len = 1; i + len <= (int)a.size() && len <= L; len++) {
				int lenb = len - ((int)a.size() - (int)b.size());
				if (lenb <= 0) continue;
				if (get_hsh(i + len, (int)a.size() - 1) != get_hsh1(i + lenb, (int)b.size() - 1)) continue;
				ans += cnt[{get_hsh(i, i + len - 1), get_hsh1(i, i + lenb - 1)}];
			}
		}
		for (int i = 0; i < (int)a.size(); i++) {
			if (get_hsh(0, i - 1) != get_hsh1(0, i - 1)) continue;
			for (auto j : special) {
				if (i + (int)j.first > (int)a.size()) continue;
				int len = j.first, lenb = len - ((int)a.size() - (int)b.size());
				if (lenb <= 0) continue;
				if (get_hsh(i + len, (int)a.size() - 1) != get_hsh1(i + lenb, (int)b.size() - 1)) continue;
				if (get_hsh(i, i + len - 1) == j.second.first && get_hsh1(i, i + lenb - 1) == j.second.second) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/*
ctzm 说得对，字符串就是哈希。

比如说这道就是哈希+根号分治乱搞搞。

n sqrt(l2 * log_2(l2))

保底 40pts,可能 60pts。

目前来说，100+100+40+20=260，比去年进步没多少，不过暴力分打的更多了。

这个 T3 感觉紫应该有了吧。

状态及其不好，感觉喘不过气。剩下的时间也不够打暴力对拍了。写一些碎碎念。

T1 在符合条件且答案最大的情况下，每个人要么选满意度最高的要么选满意度次高的。这个性质花了一段时间验证。

T2 发现如果原图上一条边不在最小生成树上，加了若干条边后它还是不在最小生成树上。
看到 k 很小先想了一个 nk log(nk) * 2^k 的算法，然后意识到不一定要一次性枚举所有选了的点，可以每一次在已有集合上多加一个点。
由于每一次算完后都只剩 n-1 条边，我们可以在每一次算 mst 时都把要计算的边控制到 O(n) 级别。
算了一下复杂度，感觉要 T，然后发现 PDF 开头说评测机 U9285K 发现可以 AC。（这应该是全国 T0 级别的评测机了吧）

T3 发现我连 KMP 都忘了，于是果断往哈希上想。随手糊了一个根号分治，对于每一个二元组，第一个长度大于 L 的字符串不会超过 L2/L 个，这些单独处理，剩下的枚举长度用 map 维护。
理论上来说，如果想拿到 60pts 要一秒 8e8，但是本机大样例跑很快。应该是大样例太水了。

然后手造了一个大样例发现本机10s.

算了，T3 按照 80pts 算吧。

那么就是分数下界为 100+80+40+20=240，上界为100+100+60+20=280。

CQ 这种环境拿一等很悬。

难道要退役了吗？

T4 不会，写了一个 n^2 * 2^n 的状压，拿完 20pts 走人。

如果人均 300+ 我要跳了。真的，就算人均 250+ 我也要跳了。如果我超常发挥和别人平均水平一样，那还玩柠檬，不玩了。
*/