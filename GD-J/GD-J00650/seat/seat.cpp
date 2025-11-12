#include<bits/stdc++.h>
#define int long long 
#define pii pair<int, int>
using namespace std;
const int INF=0x3f3f3f3f;
int n, m, idx, num, pos, ansx, ansy;
int a[105];
bool cmp(int x, int y){	return x > y; }
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> a[++idx];
	num = a[1]; sort(a+1, a+idx+1, cmp);
	for (int i=1; i<=idx; i++) if (num == a[i]) pos=i;
	ansx=pos/n; if (pos%n) ansx++;
	if (ansx&1) ansy = pos%n;
	else 		ansy = n - pos%n + 1;
	if (!ansy)  ansy+=n;
	if (ansy>n) ansy%=n;
	cout << ansx << ' ' << ansy;
	return 0;
}
