#include <bits/stdc++.h>
using namespace std;
int n, m, a[101], r;
bool cmp(int x, int y){return x > y;}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++){
		if (r == a[i]){
			r = i;
			break;
		}
	}
	int w = r / n, l = r % n;
	if (l == 0){
		if (w % 2 == 0)cout << w << " " << 1;
		else cout << w << " " << n;
	}
	else{
		cout << w + 1 << " ";
		if (w % 2 == 0)cout << l;
		else cout << n - l + 1;
	}
	cout << endl;
	return 0;
}
