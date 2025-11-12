#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>

const int N = 5e3 + 10,M = 998244353;
int f[N][N];
int n,sum;
int a[N];
int res ;
int mx;
int cnt;
long long hzj[N];
long long qzj[N];

void solve1() {
		if (a[1] + a[2] + a[3] > mx * 2) {
			std::cout << 1;
		} else {
			std::cout << 0;
		}
}

void solveman(){
	long long res = 0;
	for (int i = 3; i <= n; i ++) {
		res = (res + hzj[n - i + 1] / qzj[i]) % M;
	}
	std::cout << res;
}

int main() {
	std::freopen("polygon.in","r",stdin);
	std::freopen("polygon.out","w",stdout);
	
	std::cin >> n;
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		sum += a[i];
		mx = std::max(mx,a[i]);
	}
	if (n == 3 && mx <= 10) {
		solve1();
		return 0;
	}
	hzj[n + 1] = 1;
	for (int i = n; i >= 1; i --) {
		hzj[i] = i * hzj[i + 1] % M;
	}
	qzj[0] = 1;
	for (int i = 1; i <= n; i ++) {
		qzj[i] = i * qzj[i - 1] % M;
	}
	if (mx == 1) {
		solveman();
		return 0;
	}
	return 0;
}
