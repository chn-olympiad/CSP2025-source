#include <bits/stdc++.h>
using namespace std;

char s;
int a[1000010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int sum = 0;
/*	while(cin >> s) {
		if(s >= '0' && s <= '9') {
			a[sum] = s;
			sum++;
		}
	}
	sort(a, a + sum, cmp);
	for(int i = 0; i < sum; i++) {
		cout << a[i];
	}*/
	cin >> sum;
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
