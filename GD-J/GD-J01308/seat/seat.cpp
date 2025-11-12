#include<bits/stdc++.h>
using namespace std;
bool flag;
unsigned long long n, m, i = 0, j = 0, cnt = 0;
struct stu{
	int i, j, score;
};
bool cmp(stu x, stu y) {
	return x.score > y.score;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	vector<stu>a(n * m);
	for (int k = 0; k < n * m; k++) {
		cin >> a[k].score;
		if (cnt > n - 1 && !flag) {
			flag = 1;
			j++;
			a[k].j = j;
			cnt--;
			continue;
		}
		if (cnt <= 0 && flag) {
			flag = 0;
			j++;
			a[k].j = j;
			continue;
		}
		if (flag) {
			a[k].i = i;
			i--;
			cnt--;
		} else {
			a[k].i = i;
			i++;
			cnt++;
		}
	}
	sort(a.begin(), a.end(), cmp);
	for (int k = 0; k < n * m; k++) {
		cout << a[k].i << ' ' << a[k].j << ' ' << a[k].score << '\n';
	}
	cout << a[0].i << ' ' << a[0].j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
