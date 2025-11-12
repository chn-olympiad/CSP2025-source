#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
char a[10000010];
bool tmpp(int a,int b) {
	return a > b;
}
int main() {
	long long b[20];
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for (int i = 0; i < strlen(a); ++i) {
		if (int(a[i]) - 48 >= 0 && int(a[i]) - 48 <= 9) {
			b[a[i] - 48] += 1;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for(int j = 0; j < b[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
