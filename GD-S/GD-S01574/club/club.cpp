#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x, y;
};
bool cmp(node a, node b) {
	return a.x > b.x;
}
node a[100005][4];
node sec[100005];


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		int cc = 0;
		int cnt[4] = {0, 0, 0, 0};
		cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			a[i][1] = {x, 1};
			a[i][2] = {y, 2};
			a[i][3] = {z, 3};
			sort(a[i] + 1, a[i] + 4, cmp);
			cnt[a[i][1].y]++;
		}
		if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
			for (int i = 1 ; i <= n ; i++) ans += a[i][1].x;
			cout << ans << endl;
		} else {
			int mm;
			for (int i = 1 ; i <= 3 ; i++) {
				if (cnt[i] > n / 2) {
					mm = i;
					for (int j = 1 ; j <= n ; j++) {
						if (a[j][1].y == i) sec[++cc] = {a[j][1].x - a[j][2].x, j};
					}
				}
			}
			
			sort(sec + 1, sec + 1 + cc, cmp);
			for (int i = 1 ; i <= n / 2 ; i++) {
				ans += a[sec[i].y][1].x;
			}
			for (int i = n / 2 + 1 ; i <= cnt[mm] ; i++) {
				ans += a[sec[i].y][2].x;
			}
			for (int i = 1 ; i <= n ; i++) {
				if (a[i][1].y != mm) {
					ans += a[i][1].x;
				}
			}
			cout << ans << endl; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

