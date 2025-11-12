#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;

constexpr size_t N = 10 + 5;

int value[N * N];

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin.tie(nullptr); cout.tie(nullptr); std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int v = n * m;

	for(int i = 1; i <= v; ++i) {

		cin >> value[i];
	}

	int a = value[1];

	std::sort(value + 1, value + v + 1, [](int x, int y) {

		return x > y;
	});

	for(int i = 1, c = 1, r = 1; i <= v; ++i) {

		if(value[i] == a) {

			cout << c << ' ' << r;
			break;
		}

		if((c & 1) == 1) {

			++r;
			
			if(r > n) {
				
				++c;
				r = n;
			}
		}

		else {

			--r;

			if(r < 1) {

				++c;
				r = 1;
			}
		}
	}

	return 0;
}
