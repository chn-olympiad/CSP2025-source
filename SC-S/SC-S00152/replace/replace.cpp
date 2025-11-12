#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
typedef unsigned long long llu;
const int kN = 1000005, N = 5000005, P = 3113313113;
int n, q;
char s1[N], s2[N];
llu mpow[N];
char t1[N], t2[N];
typedef std::pair<llu, llu> mp;
class HashTable {
	struct Data {
		int nxt, val;
		mp idx;
	};
	Data p[kN + 5];
	int head[kN + 5], pcnt = 0;
	int hsh(const mp& idx) {
		return (idx.first * 1000007 + idx.second) % kN;
	}
public:
	void insert(const mp& idx) {
		int u = head[hsh(idx)];
		for (; u; u = p[u].nxt)
			if (p[u].idx == idx) {
				p[u].val++;
				return ;
			}
		p[++pcnt] = {head[hsh(idx)], 1, idx};
		head[hsh(idx)] = pcnt;
	}
	int find(const mp& idx) {
		int u = head[hsh(idx)];
		for (; u; u = p[u].nxt)
			if (p[u].idx == idx)
				return p[u].val;
		return 0;
	}
};
HashTable ht;
int main() {
	//qwq rp++!
	//Ya int_4096 desu
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	if (n <= 40000) {
		mpow[0] = 1;
		for (int i = 1; i < N; i++)
			mpow[i] = mpow[i - 1] * P;
		for (int i = 1; i <= n; i++) {
			scanf(" %s %s", s1, s2);
			int len = std::strlen(s1);
			llu hs1 = 0, hs2 = 0;
			for (int i = 0; i < len; i++) {
				hs1 = hs1 * P + (s1[i] - 'a' + 1);
				hs2 = hs2 * P + (s2[i] - 'a' + 1);
			}
//			printf("%llu -> %llu\n", hs1, hs2);
			ht.insert({hs1, hs2});
		}
		for (int rep = 1; rep <= q; rep++) {
			scanf(" %s %s", t1, t2);
			int len = std::strlen(t1);
			if (len != (int)std::strlen(t2)) {
				puts("0");
				continue;
			}
			int tail = len;
			while (tail >= 0) {
				if (t1[tail - 1] == t2[tail - 1]) tail--;
				else break;
			}
			int head = -1;
			int ans = 0;
			while (head < len) {
				llu hs1 = 0, hs2 = 0;
				for (int i = head + 1; i < len; i++) {
					hs1 = hs1 * P + (t1[i] - 'a' + 1);
					hs2 = hs2 * P + (t2[i] - 'a' + 1);
					if (i >= tail - 1)
						ans += ht.find({hs1, hs2});
				}
				head++;
				if (t1[head] != t2[head])
					break;
			}
			printf("%d\n", ans);
		}
	} else {
		while (q--)
			puts("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
CSP-S
KaoShengMiHuoXingWeiDaShang:
14:34
Open T3.
ChuanChuanTi, can't zuo.
15:55
This thing is so difficult.
Maybe T4 first.
16:12
T4 can only dfs.
Did this thing really has partical pts?
All the XingZhi were useless, and difficult.
Then put all of our hope in T1,T2.
16:23
It's sad but I have to say I can only solve by O(L^2);

*/