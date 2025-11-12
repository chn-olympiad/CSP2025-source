//AC???
#include<bits/stdc++.h>
using namespace std;
int n, m, a[105];
int xx, yy;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int num = n*m;
	for (int i = 1; i <= num; i++)
		cin >> a[i];
	int R = a[1];
	sort(a + 1, a + 1 + num, cmp);
	int rk = 0;
	for (int i = 1; i <= num; i++)
		if (a[i] == R) rk = i;		//获得排名
	int a = rk / n, b = rk % n;
	if (a % 2 == 0) {
		xx = a + 1;
		yy = b;
		if (b == 0) {
			xx = a;
			yy = 1;
		}
		cout << xx << " " << yy;
		return 0;
	} else {
		xx = a + 1;
		yy = n - b + 1;
		if (b == 0) {
			xx = a;
			yy = n;
		}
		cout << xx << " " << yy;
		return 0;
	}
	return 0;
}