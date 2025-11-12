#include <bits/stdc++.h> //O(n^2) 60pts
using namespace std;

int n, k, cnt;
int a[500010];
struct node{int l, r;}b[5000010];
bool cmp(node a, node b){return a.r < b.r;}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++){
		int sum = 0;
		for(int j = i; j <= n; j ++){
			sum ^= a[j];
			if(sum == k) b[++cnt].l = i, b[cnt].r = j;
		}
	}
	sort(b + 1, b + cnt + 1, cmp);
	int r = b[1].r, ans = 1;
	for(int i = 2; i <= cnt; i ++)
		if(b[i].l > r)
			ans ++, r = b[i].r;
	cout << ans;
	return 0;
}
