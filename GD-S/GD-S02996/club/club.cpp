#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

const int N = 1e5 + 10;
int a[N][5];
int flag = true;
int flagb = true;
int n;
int b[N];
int f[210][105][105];
int ff[2][105][105][105];

bool cmp(int a,int b) {
	return a > b;
}

void solvea() {
	std::sort(b + 1,b + 1 + n,cmp);
	int res = 0;
	for (int i = 1; i <= n / 2; i ++) {
		res += b[i];
	}
	std::cout << res << '\n';
}

void solvedp() {
	int res = 0;
	std::memset(f,-0x3f,sizeof f);
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= n / 2; j ++) {
			for (int k = 0; k <= n / 2; k ++) {
				if (j + k > i) continue;
				if (j) f[i][j][k] = std::max(f[i][j][k],f[i - 1][j - 1][k] + a[i][1]);
				if (k) f[i][j][k] = std::max(f[i][j][k],f[i - 1][j][k - 1] + a[i][2]); 
				res = std::max(res,f[i][j][k]);
			}
		}
	}
	std::cout << res << '\n';
}

void solvefp(){
	int res = 0;
	int cur = 0;
	for (int i = 0; i < 2; i ++) {
		for (int j = 0; j <= n / 2; j ++) {
			for (int k = 0; k <= n / 2; k ++) {
				for (int p = 0; p <= n / 2; p ++) {
					ff[i][j][k][p] = -0x3f3f3f3f;
				}
			}
		}
	}
	ff[cur][0][0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= n / 2; j ++) {
			for (int k = 0; k <= n / 2; k ++) {
				for (int p = 0; p <= n / 2; p ++) {
					if (j + k + p > i) continue;
					if (j) ff[cur ^ 1][j][k][p] = std::max(ff[cur ^ 1][j][k][p],ff[cur][j - 1][k][p] + a[i][1]);
					if (k) ff[cur ^ 1][j][k][p] = std::max(ff[cur ^ 1][j][k][p],ff[cur][j][k - 1][p] + a[i][2]);
					if (p) ff[cur ^ 1][j][k][p] = std::max(ff[cur ^ 1][j][k][p],ff[cur][j][k][p - 1] + a[i][3]);
					res = std::max(res,ff[cur ^ 1][j][k][p]);
				}
			}
		}
		cur ^= 1;
		for (int j = 0; j <= n / 2; j ++) {
			for (int k = 0; k <= n / 2; k ++) {
				for (int p = 0; p <= n / 2; p ++) {
					ff[cur ^ 1][j][k][p] = -0x3f3f3f3f;
				}
			}
		}
	}
	std::cout << res << '\n';	
}

void solve () {
	std::cin >> n;
	flag = flagb = true;
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][2] != 0 || a[i][3] != 0) flag = false;
		if (a[i][3] != 0) flagb = false;
		b[i] = a[i][1];
	}
	
	if (flag) {
		solvea();
		return ;
	}
	//if (n <= 200) {
		if (flagb)
			solvedp();
		else solvefp();
		return ;
	//}
}

int main () {
	std::freopen("club.in","r",stdin);
	std::freopen("club.out","w",stdout);
	int t;
	std::cin >> t;
	while (t --) {
		solve();
	}
	return 0;
}
