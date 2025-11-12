#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	vector<int>a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
