#include <iostream>
#include <algorithm>
using namespace std;
struct mynode_1 {
	int scr;
	bool is_r;
} a[1005];
bool mycmp(const mynode_1 &a, const mynode_1 &b) {
	return a.scr > b.scr;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int nm = n * m;
	for (int i = 0; i < nm; i++) {
		cin >> a[i].scr;
		if (i == 0) a[i].is_r = 1;
	}
	stable_sort(a, a + nm, mycmp);
	int c = 1, r = 1, idx = 0;
	bool dir = 1;
	while (idx < nm) {
		if (a[idx++].is_r) {
			cout << c << ' ' << r;
			break;
		}
		if (dir) {
			if (r < n) r++;
			else {
				c++;
				dir = 0;
			}
		} else {
			if (r > 1) r--;
			else {
				c++;
				dir = 1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
