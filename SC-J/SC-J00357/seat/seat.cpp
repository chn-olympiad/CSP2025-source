#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node{
	int chengji;
	int x;
	int y;
	int shunxu;
};
int a[1005];
node r;
bool cmp(int a, int b) {
	return a>b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int len = n*m;
	for (int i=1; i<=len; i++) {
		cin >> a[i];
	}
	r.chengji = a[1];
	sort(a+1, a+1+len, cmp);
	for (int i=1; i<=len; i++) {
		if (a[i] == r.chengji) {
			r.shunxu = i;
//			cout << r.shunxu << endl;
			int xx = r.shunxu/n;
			int yy = r.shunxu%n;
//			cout << yy << endl;
			if (yy == 0) {
				cout << xx << " " << n;
				return 0;
			}
			xx++;
//			cout << xx << " " << yy << endl;
			if (xx%2 == 1) {
				cout << xx << " " << yy;
				return 0;
			}
			cout << xx << " " << (n-yy+1);
			return 0;
		}
	}
	return 0;
}