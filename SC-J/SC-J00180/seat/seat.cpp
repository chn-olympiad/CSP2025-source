#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
struct P{
	int f, r;
}a[110];
bool cmp(P c, P b){
	return c.f > b.f;
}
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].f;
		a[i].r = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i].r == 1){
			int c = ceil(i * 1.0 / n);
			cout << c << " ";
			if(c % 2 == 0){
				if(i % n == 0){
					cout << 1;
					continue;
				}
				cout << n - i % n + 1;
			}
			else{
				if(i % n == 0){
					cout << n;
					continue;
				}
				cout << 1 + i % n - 1;
			}
		}
	}
	return 0;
}