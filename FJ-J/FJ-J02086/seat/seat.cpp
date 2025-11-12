#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105];
	cin >> n >> m;
	int len = n * m;
	for (int i = 0; i < len; i++)
		cin >> a[i];
	int flag1 = a[0];
	int flag2;
	sort(a, a + len, cmp);
	for (int i = 0; i < len; i++)
		if (a[i] == flag1){
			flag2 = i + 1;
			break;
		}
	int cnt1 = flag2 / n, cnt2 = flag2 % n;
	if (cnt2 == 0){
		if (cnt1 % 2 == 1) cout << cnt1 << ' ' << n;
		else cout << cnt1 << ' ' << 1;
	}else {
		if (cnt1 % 2 == 1) cout << cnt1 + 1 << ' ' << n - cnt2 + 1;
		else cout << cnt1 + 1 << ' ' << 1 + cnt2 - 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
