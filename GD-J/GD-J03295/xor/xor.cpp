#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

const int N = 5e5 + 10;
int n,k;
int a[N];
int cnt;
int cnt0;
int flag1,flag2 = true;

void solve1(){
	std::cout << n / 2;
}

void solveb() {
	if (k == 1) {
		std::cout << cnt;
	} else {
		std::cout << cnt0 + cnt / 2;
	}
}

int main () {
	std::freopen("xor.in","r",stdin);
	std::freopen("xor.out","w",stdout);
	
	std::cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		if (a[i] == 1) cnt ++;
		if (a[i] == 0) cnt0 ++;
		if (a[i] != 1) flag1 = true;
		if (a[i] != 1 && a[i] != 0) flag2 = false;
	}
	if (k == 0 && !flag1) {
		solve1();
		return 0;
	}
	if (k <= 1 && flag2) {
		solveb();
		return 0;
	}
	return 0;
}
