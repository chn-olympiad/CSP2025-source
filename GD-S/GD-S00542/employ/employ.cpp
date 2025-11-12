#include<bits/stdc++.h>
using namespace std;

#define F(i, l, r) for(int i = (l); i <= (r); ++i)
#define dF(i, r, l) for(int i = (r); i >= (l); --i)
#define pb push_back
#define vi vector<int>

template<typename T> void debug(string s, T x) {
	cerr << "[ " << s << "] = [" << x << "]\n";
}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {
	int t = 0;
	F(i, 0, (int)s.size() - 1) if(s[i] =='(') t++;
	else if(s[i] == ')') t--;
	else if(s[i] == ',' && !t) {
		cerr << "[" << s.substr(0, i) << "] = [" << x << "] | ";
		debug(s.substr(s.find_first_not_of(' ', i + 1)), args...);
		break;
	}
}

#ifdef orzz
#define Debug(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define Debug(...) 
#endif

int ri() {
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' ||c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	} return x * f;
}

const int _ = 2e5 + 5;
const int mod = 998244353;

int n, m, c[_];

char S[_];

int f[2][(1 <<18)][21];

void add(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w",stdout);
	n = ri(), m = ri();
	scanf("%s", S + 1);
	// bool flg = 1;
	// F(i, 1, n) flg &= (S[i] == '1');
	// if(flg) {
	// 	int ans = 1;
	// 	F(i, 1, n) ans = 1ll *ans * i % mod;
	// 	cout << ans << '\n';
	// 	return 0;
	// }
	F(i, 1, n) c[i] = ri();	
	f[0][0][0] = 1;
	F(i, 1, n) {
		int nw = i & 1, lst = nw ^ 1;
		F(s, 0, (1 << n) - 1) F(t, 0, n) if(f[lst][s][t]) {
			F(j, 1, n) if(~s >> (j - 1) & 1) {
				int g = (S[i] == '0' || (t >= c[j]));
				add(f[nw][s|(1<<(j-1))][t+g], f[lst][s][t]);
			}
		}
	}
	int ans = 0;
	F(j, 0, n-m) add(ans, f[n&1][(1<<n)-1][j]);
	cout << ans << '\n';
}