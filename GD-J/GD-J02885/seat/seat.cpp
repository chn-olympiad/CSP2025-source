#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int n,m,xm,id;
int a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	xm = a[1];
	sort(a + 1,a + 1 + n * m);reverse(a + 1,a + 1 + n * m);
	for (int i = 1;i <= n * m;i++) if (a[i] == xm) id = i;
	int lie = (id - 1) / n + 1;
	if (lie & 1) cout << lie << " " << (((id - 1) % n + 1)) << "\n";
	else cout << lie << " " << (n - ((id - 1) % n + 1) + 1) << "\n";
	return 0;
}
