#include<bits/stdc++.h>
using namespace std;
int n, m, ha, li;
int a[110];
bool cmp(int x, int y) {return x > y;}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i];
	}
	int s = a[1];
	sort(a+1, a+1+n*m, cmp);
	int l = 1, r = 100, mid;
	while (l <= r) {
		mid = (l+r)>>1;
		if (a[mid] > s) l = mid+1;
		else if (a[mid] < s) r = mid-1;
		else break;
	}
	li = (mid + n - 1) / n;
	if (li & 1) ha = (mid - 1) % n + 1;
	else ha = n - (mid - 1) % n;
	cout << li << ' ' << ha;
	return 0;
}

