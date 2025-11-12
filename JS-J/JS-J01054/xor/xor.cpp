#include <bits/stdc++.h>
using namespace std;
int a[500001], vis[500001], n, k, ans = 1, sum = 0;

struct node{
	int s, e;
}l[500001];

bool cmp(node x, node y){
	return x.e < y.e;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		vis[i - 1] = 0;
		for (int j = i; j <= n; j++){
			vis[j] = vis[j - 1] ^ a[j];
			if (vis[j] == k) {
				sum++;
				node f = {i, j};
				l[sum] = f;
				break;
			}
		}
	}
	sort(l + 1, l + sum + 1, cmp);
	int last = l[1].e;
	for (int i = 2; i <= sum; i++){
		if (l[i].s > last) {
			ans++;
			last = l[i].e;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
