#include <iostream>
#include <string>

#define repm(i, begin, end) for (int i = begin; i < end; i += 1)
#define rep(i, n) repm(i, 0, n)

using namespace std;

void fileio() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fileio();
	
	string str;
	cin >> str;
	
	int numc[10] {0};
	for (auto c: str) {
		if ('0' <= c && c <= '9') {
			numc[c-'0'] += 1;
		}
	}
	
	bool nzero = false;
	
	rep(i, 10) {
		int num = 10 - i - 1;
		
		if (numc[num] != 0) {
			if (num == 0 && !nzero) {
				cout << 0 << endl;
				return 0;
			}
			
			nzero = true;
			rep(j, numc[num]) {
				cout << num;
			}
		}
	}
	
	cout << endl;
	return 0;
}
