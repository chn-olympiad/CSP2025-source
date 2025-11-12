#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <cmath>

std::array <int, 110> arr;
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out","w", stdout);
	
	int n, m;
	std::cin >> n >> m;
	for (int i=0; i<n*m; i++) {
		std::cin >> arr[i];
	}
	int rs = arr[0];
	std::sort (arr.begin(), arr.end(), std::greater<int>());
	int idx=0;
	for (int i=0; i<n*m; i++)
		if (arr[i] == rs)
			idx = i;
	int c = idx/n+1;
	int r;
	if (c%2)
		r = idx%n+1;
	else
		r = n-idx%n;
	std::cout << c << ' ' << r;
}
