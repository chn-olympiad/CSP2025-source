#include<bits/stdc++.h>
using namespace std;
int a[110], c[11][11], r, num = 0;
int n, m;
bool cmp(int c1, int c2){
	return (c1 > c2);
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int q = n * m;
	for(int i = 1; i <= q; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + q + 1, cmp);
	int f = 0;
	for(int i = 1; i <= n * m; i++){
		if(a[i] == r){
			f = i;
			break;
		}
	}
	int c1 = f / m + 1;
	int c2 = f % m;
	if(f % m == 0) c1--, c2 = n;
	if(c1 % 2 == 0) cout << c1 << " " << n - c2 + 1;
	else cout << c1 << " " << c2;
	return 0;
}
