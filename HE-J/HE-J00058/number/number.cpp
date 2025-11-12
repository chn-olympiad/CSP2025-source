#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;

string a;
char b[N];
int k;

int cmp(char a, char b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if ((int)a[i] <= '9' && (int)a[i] >= '0') {
			b[k] = a[i];
			k++;
		}
	}
	sort(b, b+k, cmp);
	cout << b;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
