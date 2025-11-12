#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp (int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) cin >> a[i];
	int t = a[1], t2 = 0;
	sort(a + 1, a + (n*m) + 1, cmp);
	for (int i = 1; i <= n*m; i++) {
		if (a[i] == t) {
			t2 = i;
			break;
		}
	}
	int y = t2 / n; 
	int x = t2 % n; 
	int z; 	
	if (x) {
		cout << y+1 << " ";
		z = y+1;
	} else {
		cout << y << " ";
		z = y;
	}
	if (z % 2 == 0) { //当处于由下往上的顺序时 
		if (!x) cout << 1; //倒数第一个位置 
		else cout << n - x + 1;  
	} else {
		if (!x) cout << n;
		else cout << x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
