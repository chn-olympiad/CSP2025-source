#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,s1,s2;
bool cmp ( int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
		if(a[i] == i) {
			s1 ++;
		} else if(a[i] == n * m - i + 1) {
			s2 ++;
		}
	}
	t = a[1];
	if(s1 == n * m) {
		if(m % 2 == 0) {
			cout << m << " " << n;
			return 0;
		} else {
			cout << m << " " << 1;
			return 0;
		}
	} else if(s2 == n * m) {
		cout << 1 << " " << 1;
		return 0;
	}
	sort ( a+1, a+n*m+1, cmp);
	for (int i=1; i <= n * m; i ++) {
		if(a[i] == t) {
			t = i;
			break;
		}
	}
	int hang = t % n != 0 ? t % n : 1;//hang
	int li = (t + n - 1) / n;//lie
	if (li % 2 == 1) { //ji shu
		cout << li << " " << hang;
	} else {//ou daozhe
		cout << li <<" " << n - hang + 1;
	}
	return 0;
}
