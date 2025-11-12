#include <iostream>
#include <cstdio> 
#include <map>
using namespace std;
int a[500010];
int sum[500010];
int mu[500010];
int last[500010];
map <int, int> m;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++)mu[i] = sum[i] ^ k;
	for (int i = 0; i <= n; i++){
		if (m.count(mu[i]))last[i] = m[mu[i]] + 1;
		m[sum[i]] = i;
	}
	int zui = 0, cnt = 0;
	for (int i = 1; i <= n; i++){
		if (last[i] <= zui)continue;
		cnt++;
		zui = i;
	}
	cout << cnt;
	return 0;
} 
