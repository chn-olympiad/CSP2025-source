#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i <= e; i++)
using namespace std;
typedef long long ll;
const int N = 1e2 + 10, inf = 0x3f3f3f3f;
struct node{
	int val, id, reid;
}a[N];
int n, m, ans1, ans2, identify, k, x, y;
bool cmp(node a, node b){
	return a.val > b.val;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	k = n * m;
	f(i, 1, k){
		a[i].id = i;
		cin >> a[i].val;
	}
	sort(a + 1, a + 1 + k, cmp);
	f(i, 1, k){
		a[i].reid = i;
		if (a[i].id == 1) identify = i;
	}
	x = (identify - 1) / n, y = (identify - 1) % n;
	ans1 = x + 1;
	if (x % 2) ans2 = n - y;
	else ans2 = y + 1;
	cout << ans1 << ' ' << ans2;
	return 0;
}
