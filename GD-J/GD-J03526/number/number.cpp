#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long unsigned int a[10], x;
string n;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> n;
	for(long long unsigned int i = 0; i < n.size(); i++) {
		if(n[i] >= '0' && n[i] <= '9') {
			a[n[i] - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--) {
		for(long long unsigned int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
