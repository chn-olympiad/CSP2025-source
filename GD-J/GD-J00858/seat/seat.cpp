#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n, m, a[110], pos, num;
bool cmp(int u, int v){
	return u > v;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) cin >> a[i];
	num = a[1];
	sort(a + 1, a + n*m + 1, cmp);
	for (int i = 1; i <= n*m; i++)
		if (a[i] == num){
			pos = i;
			break;
		}
	
	int q = pos/n, r = pos-q*n;
	if (q % 2 == 1){
		if (r == 0) cout << q << " " << n;
		else cout << q+1 << " " << n-r+1;
	}
	else {
		if (r == 0) cout << q << " " << 1;
		else cout << q+1 << " " << r;
	}
	cout << endl;
	return 0;
}
