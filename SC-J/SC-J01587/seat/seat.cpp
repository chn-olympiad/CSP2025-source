#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n, m;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	vector<int> a(n*m);
	for(int i = 0; i < n*m; i++) {
		cin >> a[i];
	}
	int p = a[0], l;
	sort(a.begin(), a.end(), [](int a, int b){
		return a>b;
	});
	for(int i = 0; i < n*m; i++) {
		if(a[i] == p)l = i;
	}
	l++;
	if(((l-1)/n+1)%2 == 1) {
		cout << (l-1)/n+1 << ' ' << (l%n==0?n:l%n);
	}else {
		cout << (l-1)/n+1 << ' ' << n-(l%n==0?n:l%n)+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}