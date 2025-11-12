#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

int t[20];
std::string a;

int main() {
	std::freopen("number.in","r",stdin);
	std::freopen("number.out","w",stdout);
	std::cin >> a;
	int n = a.size();
	for (int i = 0; i < n; i ++) {
		if (std::isdigit(a[i])) {
			t[a[i] - '0'] ++;
		}
	}
	
	for (int i = 9; i >= 0; i --) {
		while (t[i] --) {
			std::cout << i;
		}
	}
	return 0;
} 
