#include <bits/stdc++.h>
using namespace std;

int n, m, arr[1000], x, ans1, ans2;

bool cmp(int a, int b){
	return a > b;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0;i < n * m;i++)    cin >> arr[i];
	x = arr[0];
	sort(arr, arr + n * m, cmp);
	int a = 0;
	for (int i = 0;i < n * m;i++){
		if (arr[i] == x){
			a = i + 1;
			break;
		}
	}
	ans1 = (a - 1) / n + 1;
	if (ans1 % 2 == 1)    ans2 = a - (ans1 - 1) * n;
	else    ans2 = ans1 * n - a + 1;
	cout << ans1 << " " << ans2;
	return 0;
}
