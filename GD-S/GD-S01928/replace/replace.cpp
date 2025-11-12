#include<bits/stdc++.h>
using namespace std;

template<typename T> void qr(T &x) {
	x = 0; char c = getchar(); int f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') {
		f = -1;
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + (c - '0');
	}
	x *= f;
}

template<typename T> void qw(T x) {
	if (x < 0) {
		putchar('-');
	}
	if (x > 9) {
		qw(x / 10);
	}
	putchar(x % 10 + '0');
}

const int M = 5e6 + 10;
const int N = 2e5 + 10;

char sa[M], sc[M];

int cha[N][27], chc[N][27];
int lena, lenc;
vector<int> eda[M], edc[M];
int va[N], vc[N];

void inserta(int x) {
	int p = 0;
	for (int i = 1; sa[i]; i ++) {
		int j = sa[i] - 'a';
		if (!cha[p][j]) {
			++lena;
			cha[p][j] = lena;
		}
		p = cha[p][j];
	}
	eda[p].push_back(x);
}

void insertc(int x) {
	int p = 0;
	for (int i = 1; sc[i]; i ++) {
		int j = sc[i] - 'a';
		if (!chc[p][j]) {
			++lenc;
			chc[p][j] = lenc;
		}
		p = chc[p][j];
	}
	edc[p].push_back(x);
}

int ans;
void query_a() {
	int p = 0;
	for (int i = 1; sa[i]; i ++) {
		int j = sa[i] - 'a';
		if (!cha[p][j]) {
			p = 0;
			continue;
		}
		p = cha[p][j];
		for (auto k : eda[p]) {
			va[k] = i;
		}
	}
}

void query_c() {
	int p = 0;
	for (int i = 1; sc[i]; i ++) {
		int j = sc[i] - 'a';
		if (!chc[p][j]) {
			p = 0;
			continue;
		}
		p = chc[p][j];
		for (auto k : edc[p]) if (va[k] == 1) {
			ans ++;
		}
	}
}

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	lena = lenc = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> (sa + 1) >> (sc + 1);
		inserta(i);
		insertc(i);
	}
	
	for (int i = 1; i <= q; i ++) {
		cin >> (sa + 1) >> (sc + 1);
		ans = 0;
		query_a();
		query_c();
		query_a();
		cout << ans << "\n";
	}
	
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//
//template<typename T> void qr(T &x) {
//	x = 0; char c = getchar(); int f = 1;
//	for (; !isdigit(c); c = getchar()) if (c == '-') {
//		f = -1;
//	}
//	for (; isdigit(c); c = getchar()) {
//		x = x * 10 + (c - '0');
//	}
//	x *= f;
//}
//
//template<typename T> void qw(T x) {
//	if (x < 0) {
//		putchar('-');
//	}
//	if (x > 9) {
//		qw(x / 10);
//	}
//	putchar(x % 10 + '0');
//}
//
//typedef long long LL;
//const int N = 2e3 + 10;
//const LL P = 1e9 + 7;
//char sa[N], sb[N];
//LL hsa[N][N], hsb[N][N];
//LL hha[N], hhb[N]
//int len[N];
//
//int main () {
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
//	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	int n, q;
//	cin >> n >> q;
//	for (int i = 1; i <= n; i ++) {
//		cin >> (sa + 1) >> (sb + 1);
//		len[i] = strlen(sa + 1);
//		hsa[i][0] = 0;
//		for (int j = 1; sa[j]; j ++) {
//			hsa[i][j] = hsa[i][j - 1] * P + sa[j] - 'a';
//		}
//		hsb[i][0] = 0;
//		for (int j = 1; sb[j]; j ++) {
//			hsb[i][j] = hsb[i][j - 1] * P + sb[j] - 'a';
//		}
//	}
//	for (int i = 1; i <= q; i ++) {
//		cin >> (sa + 1) >> (sb + 1);
//		hha[0] = 0;
//		for (int j = 1; sa[j]; j ++) {
//			hha[j] = hha[j - 1] * P + sa[j] - 'a';
//		}
//		
//		hhb[0] = 0;
//		for (int j = 1; sb[j]; j ++) {
//			hhb[j] = hhb[i][j - 1] * P + sb[j] - 'a';
//		}
//		
//		for (int j = 1; j <= q; j ++) {
//			for (int k = 1; s[k]; k ++) {
//				if (cmp(k, k + len[j] - 1)) {
//					
//				}
//			} 
//		}
//	}
//	
//	return 0;
//}
