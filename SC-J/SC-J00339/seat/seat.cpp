#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int a[MAXN];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int id = 0;
	for (int i = 1; i <= n * m; i++){
		if (a[i] == x){
			id = i;
		}
	}
	int c = ceil((double)id / n), r = 0;
	if (c & 1){
		r = id % n;
		if (r == 0) r = n;
	}
	else{
		r = n - id % n + 1;
		if (r == n + 1) r = 1;
	}
	cout << c << " " << r << endl;
	return 0;
}