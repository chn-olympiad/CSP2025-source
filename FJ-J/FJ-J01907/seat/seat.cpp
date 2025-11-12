#include<bits/stdc++.h>
#define int long long
const int N = 1e1 + 10;
int n, m, a[N * N];
int l;
int cmp(int a,int b){
	return a > b;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		std::cin >> a[i];
	}
	l = a[1];
	std::sort(a + 1,a + n * m + 1,cmp);
	int sum = 1;
	while (a[sum] != l) sum++;
	int l = sum / n, r;
	std::cout<<sum<<"\n";
	if (l * n != sum) {
		l++;
		std::cout << l << " ";
		if (l % 2 == 1) {
			r = sum - (l - 1) * n;
			std::cout << r;
		}
		else {
			r = m-(sum - (l - 1) * n) + 1;
			std::cout << r;
		}
	}
	else {
		std::cout << l << " ";
		if (l % 2 == 1) {
			r = sum - (l - 1) * n;
			std::cout << r;
		}
		else {
			r = m-(sum - (l - 1) * n) + 1;
			std::cout << r;
		}
	}
	return 0;
}
