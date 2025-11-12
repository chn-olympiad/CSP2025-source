#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], cnt;

bool cmp(int q, int p){
	return q > p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int score = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i++) if(a[i] == score) cnt = i;
	int x = cnt / n + ((cnt % n) ? 1 : 0), y = cnt % (2 * n);
	if(!y) y = 2 * n;
	if(y <= n) cout << x << " " << y;
	else cout << x << " " << 2 * n - y + 1;
	return 0;
}
