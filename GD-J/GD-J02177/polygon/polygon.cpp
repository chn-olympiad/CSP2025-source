#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

bool cmp(int ax, int ay) {
	return ax > ay;
}

int a[5050];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(a, 0, sizeof(a));
	int n;
	cin >> n;
	int sum = 0;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a+1, a+1+n, cmp);
	if(sum <= a[1] * 2) cout << 0;
	else cout << 1;
}
