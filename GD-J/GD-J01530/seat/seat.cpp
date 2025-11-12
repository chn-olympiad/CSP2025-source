#include<bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t, p;
	cin >> n >> m >> a[1];
	t = a[1];
	for(int i=2; i<=n*m; i++) cin >> a[i];
	sort(a+1, a+1+n*m, cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i] == t){
			p = i - 1;
			break;
		}
	}
	cout << p / n + 1 << " " << (p / n % 2 == 0 ? p % n + 1 : n - p % n);
	return 0;
}
