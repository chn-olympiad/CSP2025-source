#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int tr[50000007];
int arr[10000007];
int me[10000007];

void bup(int x){
	tr[x] = tr[2 * x] ^ tr[2 * x + 1];
}
void build(int l, int r, int x){
	if (l == r)    tr[x] = arr[l];
	else {
		int mid = (l + r) / 2;
		build(l, mid, 2 * x);
		build(mid + 1, r, 2 * x + 1);
		bup(x);
	}
}

int get(int l, int r, int a, int b, int x){
	int nans = 0;
	if (l <= a && r >= b)    return tr[x];
	if (a == b)    return 0;
	else {
		int mid = (a + b) / 2;
		int g = get(l, r, a, mid, 2 * x);
		int h = get(l, r, mid + 1, b, 2 * x + 1);
		nans = g ^ h;
	}
	return nans;
}

int an(int l, int r){
	int ns = 0;
	for (int i = l;i <= r;i++){
		for (int j = l;j <= r && i <= j;j++){
			if (get(i, j, 1, n, 1) == k){
				ns++;
				i = j + 1;
			}
		}
	}
	return ns;
}

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)    cin >> arr[i];
	build(1, n, 1);
	int cnt = 0;
	for (int i = 1;i <= n;i++){
		if (arr[i] == k)    me[cnt++] = i;
	}
//	if (me[cnt - 1] != n)    me[cnt++] = n;
	if (me[0] != 1)    ans += an(1, me[0] - 1);
	if (me[cnt - 1] != n)    ans += an(me[cnt - 1] + 1, n);
	for (int i = 0;i < cnt - 1;i++){
		if (me[i + 1] - me[i] > 1)
			ans += an(me[i] + 1, me[i + 1] - 1);
	}
	cout << ans + cnt;
	return 0;
}
