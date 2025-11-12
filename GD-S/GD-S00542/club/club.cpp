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

int n, a[_][3], b[_], mx[_][2];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w",stdout);
	int T = ri();
	while(T--) {
		n= ri();
		F(i, 1, n) a[i][0] = ri(), a[i][1] = ri(), a[i][2] = ri();
		F(i, 1, n) {
			int Mx = max(max(a[i][0],a[i][1]), a[i][2]);
			mx[i][0] = mx[i][1] = -1;
			F(j, 0, 2) {
				if(a[i][j] > mx[i][0]) {
					mx[i][1] = mx[i][0], mx[i][0] = a[i][j];
				} else {
					mx[i][1] = max(mx[i][1],a[i][j]);
				}
			}
			if(Mx == a[i][0]) {
				b[i] = 0;
			} else if(Mx == a[i][1]) {
				b[i] = 1;
			} else {
				b[i] = 2;
			}
		}
		vi num(3, 0);
		F(i, 1, n) num[b[i]]++;
		int ans = 0;
		F(i, 1, n) ans += a[i][b[i]];
		int id = -1;
		if(num[0] > n / 2) id = 0;
		else if(num[1] > n / 2) id = 1;
		else if(num[2] > n / 2) id = 2;
		if(~id) {
			vi a;
			F(i, 1, n) if(b[i] == id) {
				a.pb(i);
			}
			sort(a.begin(), a.end(), [&](int x, int y) { return mx[x][0] -mx[x][1] < mx[y][0] - mx[y][1]; });
			int KK = num[id]- n/2;
			assert(a.size() == num[id]);
			F(i, 0, KK - 1) {
				ans += -mx[a[i]][0]+mx[a[i]][1];
			}
		}
		printf("%d\n", ans);
	}
}