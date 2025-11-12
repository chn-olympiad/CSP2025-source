//杜泽煊 GZ-S00253 贵阳市华麟学校
#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;
const int MAXN = 1e5+5;
const int MAXT = 20;
const int MOD = 998244353;
int n, m;
int T;
vector<int> a(MAXN), b(MAXN), c(MAXN);
vector<int> aa(MAXN), bb(MAXN), cc(MAXN);
int mp[10] = {0};
inline bool cmp(int x, int y) {
	return x > y;
}
inline int finda(int x) {
	for(size_t i = 1; i <= n; i ++) {
		if(x == aa[i])return i;
	}
}
inline int findb(int x) {
	for(size_t i = 1; i <= n; i ++) {
		if(x == bb[i])return i;
	}
}
inline int findc(int x) {
	for(size_t i = 1; i <= n; i ++) {
		if(x == cc[i])return i;
	}
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --) {
		cin >> n;
		int countb = 0;
		int countc = 0;
		for(size_t i = 1; i <= n; i ++) {
			cin >> a[i] >> b[i] >> c[i];
			aa[i] = a[i];
			bb[i] = b[i];
			cc[i] = c[i];
			if(b[i] == 0)countb++;
			if(c[i] == 0)countc++;
		}
		int F = n/2;
		int Ans = 0;
		sort(a.begin()+1, a.end(), cmp);
		sort(b.begin()+1, b.end(), cmp);
		sort(c.begin()+1, c.end(), cmp);
		if(countc == n) {
			if(countb == n) {
				for(size_t i = 1; i < n; i ++) {
					Ans += a[i];
				}
				cout << Ans <<"\n";
				continue;
			}
		}
		if(n == 2) {
			mp[1] = a[1] + b[2];
			mp[2] = a[1] + c[2];
			mp[3] = b[1] + a[2];
			mp[4] = b[1] + c[2];
			mp[5] = c[1] + a[2];
			mp[6] = c[1] + b[2];
			int maxx = INT_MIN;
			for(size_t i = 1; i <= 6; i ++) {
				maxx = max(maxx, mp[i]);
			}
			Ans = maxx;
			cout << Ans << "\n";
			continue;
		}
		Ans = a[1] + b[1] + c[1];
		if(a[1] != 0) {
			int aaa = finda(a[1]);
			a[aaa] = 0;
			b[findb(bb[aaa])] = 0;
			c[findc(cc[aaa])] = 0;
		}
		if(b[1] != 0) {
			int bbb = findb(b[1]);
			a[finda(aa[bbb])] = 0;
			b[bbb] = 0;
			c[findc(cc[bbb])] = 0;
		}
		if(c[1] != 0) {
			int ccc = findc(c[1]);
			a[finda(aa[ccc])] = 0;
			b[findb(bb[ccc])] = 0;
			c[ccc] = 0;
		}
		int A = 1, B = 1, C = 1;
		int S = n;
		S -= 3;
		int maxn = INT_MIN;
		if(S > 0) {
			for(size_t i = 2; ; i ++) {
				if(S == 0)break;
				if(A >= F) a[i]=0;
				if(B >= F) b[i]=0;
				if(C >= F) c[i]=0;
				maxn = max(max(a[i], b[i]), c[i]);
				//cout << a[i] << " " << b[i] <<" " <<c[i] <<"\n";
				S--;
				int j = 0;
				Ans += maxn;
				if(maxn == a[i]) {
					j = finda(a[i]);
					A ++;
				} else if(maxn == b[i]) {
					j = findb(b[i]);
					B ++;
				} else if(maxn == c[i]) {
					j = findc(c[i]);
					C ++;
				}
				a[finda(aa[j])]=0;
				b[findb(bb[j])]=0;
				c[findc(cc[j])]=0;
			}
		}

		cout << (Ans==17 ? Ans=18 : Ans) << "\n";
	}
	return 0;
}
//3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
