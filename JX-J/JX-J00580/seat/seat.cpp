#include<bits/stdc++.h>
using namespace std;

int n,m,a[150],p;

bool cmp(int aa,int bb) {
    return aa > bb;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	int t = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= n * m;i++) {
        if (a[i] == t) {
            p = i; break;
        }
	}
	int x = (p - 1) / n,y = (p - 1) % n;
	if (x % 2 == 0) cout << x + 1 << ' ' << y + 1;
	else cout << x + 1 << ' ' << n - y;
	return 0;
}
