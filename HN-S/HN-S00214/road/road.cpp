// sto cch,pty,jol3r,jiangly,xudyh,xht,clz,cz,wcq orz	
#include <algorithm>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;
using LL = long long;

const LL kMaxN = 2e6 + 1, kMaxM = 2e4 + 1, kMaxL = 11;

ifstream cin("road.in");
ofstream cout("road.out");

LL n, m, k, ans = 1e18, c[kMaxL], f[kMaxM], siz[kMaxM], a[kMaxL][kMaxM];
bool fl[kMaxL];
struct E {
	LL u, v, w;
} e[kMaxN], o[kMaxN];

inline LL F(LL x) {
	return f[x] = f[x] == x ? x : F(f[x]);
}

inline bool U(LL x, LL y) {
	LL fx = F(x), fy = F(y);
	if (fx == fy) {
		return 0;
	}
	f[fy] = fx;
	siz[fx] += siz[fy];
	return 1;
}

LL G() {
	LL s = 0;
	for (LL i = 1; i <= n; i++) {
		f[i] = i, siz[i] = 1;
	}
	LL h = 0, ct = n;
	for (LL i = 1; i <= k; i++) {
		f[i + n] = i + n;
		if (fl[i]) {
			siz[i + n] = 1;
			ct++;
			s += c[i];
			for (LL j = 1; j <= n; j++) {
				o[++h] = {j, i + n, a[i][j]};
			}
		}
	}
	sort(o + 1, o + h + 1, [](E a, E b) {
		return a.w < b.w;
	});
	LL mxsiz = 0;
	for (LL i = 1, j = 1; i <= m; i++) {
		if (mxsiz == ct) {
			break;
		}
		while (o[j].w <= e[i].w && j <= h) {
			if (U(o[j].u, o[j].v)) {
				s += o[j].w;
			}
			mxsiz = max(mxsiz, siz[F(o[j].u)]);
			j++;
			if (mxsiz == ct) {
				break;
			}
		}
		if (mxsiz == ct) {
			break;
		}
		if (U(e[i].u, e[i].v)) {
			s += e[i].w;
		}
		mxsiz = max(mxsiz, siz[F(e[i].u)]);
	}
//	for (LL i = 1; i <= k; i++) {
//		cout << fl[i] << " ";
//	}
//	cout << s << '\n';
	return s;
}

void D(LL x) {
	if (x > k) {
		ans = min(ans, G());
		return;
	}
	D(x + 1);
	fl[x] = 1;
	D(x + 1);
	fl[x] = 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (LL i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (LL i = 1; i <= k; i++) {
		cin >> c[i];
		for (LL j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if (k == 0) {
		for (LL i = 1; i <= n; i++) {
			f[i] = i, siz[i] = 1;
		}
		for (LL i = 1; i <= k; i++) {
			f[i + n] = i + n;
			for (LL j = 1; j <= n; j++) {
				e[++m] = {j, i + n, a[i][j]};
			}
		}
		sort(e + 1, e + m + 1, [](E a, E b) {
			return a.w < b.w;
		});	
		LL s = 0, mxsiz = 1;
		for (LL i = 1; i <= m; i++) {
			if (mxsiz == n) {
				break;
			}
			if (U(e[i].u, e[i].v)) {
				s += e[i].w;
			}
			mxsiz = max(mxsiz, siz[F(e[i].u)]);
		}
		cout << s << '\n';
		return 0;
	}
	sort(e + 1, e + m + 1, [](E a, E b) {
		return a.w < b.w;
	});	
	D(1);
	cout << ans << '\n';
  return 0;
}
/*
草 怎么是O(2*k(nlogn+m)) 的

ccf机子跑得过去吗？

先写特殊性质吧 

来个 48pts 

O((m+nk)log(m+nk)) 的 

好的，写完了

ccf 能跑 1e9 吗

LLel Core Ultra 9 285K CPU @ 3.70 GHz 

比我家的好 10 倍 woc 


过A性质了

我草我左边的左边的哥们儿已经打了1.5h的摆了

应该不会退役了吧/yiw

所以关注 CuteGirlGC(681755) 谢谢喵 

不对啊

这个暴力只有 16pts

f**k

草

我不会真的退役了吧/ll

别啊

ccf数据弱点吧/ll 

小样例过了

测下大样例

这机子跑得贼几把慢

都不知道自己T没T

fk 

？第四个大样例怎么没过？？？ 


ooook 调了 20min 终于过了

ccf 对我好一点/ll 
*/ 
