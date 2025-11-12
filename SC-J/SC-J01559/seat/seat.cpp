#include<bits/stdc++.h>
using namespace std;
struct A{
	int p, id;
}a[110];
int dr[] = {1, -1, 1, -1}, d = 0;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r = 1, c = 1;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		a[i].id = i;
		cin >> a[i].p;
	}
	sort(a + 1, a + n * m + 1, [](A x, A y){return x.p > y.p;});
	for(int i = 1; i <= n * m; i++){
		if(a[i].id == 1){
			cout << c << ' ' << r;
			return 0;
		}
		if(i % n == 0) c++, d++;
		else r += dr[d];
	}
	return 0;
}