#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[105];
bool cmp (int a, int b){
	return a > b;
} 
int main (){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
		cin >> a[i];
	int r = a[1], cnt;
	sort (a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i ++){
		if (a[i] == r){
			cnt = i;
			break;
		}
	}
	cout << (cnt - 1) / n + 1 << ' ';
	if (((cnt - 1) / n + 1) % 2 == 1)
		cout << cnt - (cnt - 1) / n * n;
	else
		cout << n + 1 - (cnt - (cnt - 1) / n * n);
	return 0;  
} 
