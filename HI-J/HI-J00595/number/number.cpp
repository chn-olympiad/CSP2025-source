#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e6 + 10;
int cnt[20],n;
char chr[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> (chr + 1);
	n = strlen(chr + 1);
	for (int i = 1; i <= n; i++) {
		if ('0' <= chr[i] && chr[i] <= '9') {
			cnt[chr[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (cnt[i]--) {
			cout << i;
		}
	}
	return 0;
}
