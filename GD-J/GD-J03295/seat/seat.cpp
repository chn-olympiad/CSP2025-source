#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

int n,m;
int a[200],fin,idx;

bool cmp(int a,int b) {
	return a > b; 
}

int main() {
	std::freopen("seat.in","r",stdin);
	std::freopen("seat.out","w",stdout);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		std::cin >> a[i];
	}
	fin = a[1];
	std::sort(a + 1,a + 1 + n * m,cmp);
	
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == fin) {
			idx = i;
			break;
		}
	}
	
	int num = idx / n;
	
	if (idx % n == 0) {
		if (num % 2) {
			std::cout << num << ' ' << n;
		} else {
			std::cout << num << ' ' << 1;
		}
		return 0;
	}
	
	if (num % 2 == 0) {
		std::cout << (num + 1) << ' ' << idx % n;
		return 0; 
	}
	if (num % 2) {
		std::cout << (num + 1) << ' ' << n - (idx % n) + 1;
		return 0; 
	} 
	
	return 0;
}
