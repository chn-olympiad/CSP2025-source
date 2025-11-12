#include <bits/stdc++.h>
using namespace std;

struct node {
	int v, id;
}a[105];

bool cmp(node s1, node s2) {
	return s1.v > s2.v;
}
int n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	
	int l = n * m;
	for (int i = 1; i <= l; i++) {
		cin >> a[i].v;
		a[i].id = i;
	}
	
	sort(a + 1, a + l + 1, cmp);
	
	int x = 1, y = 0;
	bool flag = 1;
	for (int i = 1; i <= l; i++) {
		if (i % n == 1 && i != 1) {
			x++;
			if (a[i].id == 1) {
				cout << x << ' ' << y;
				break;
			}
			if (flag) flag = false;
			else flag = true;
			continue;
		} 
		
		if (flag) y++;
		else y--;
		
		if (a[i].id == 1) {
			cout << x << ' ' << y;
			break;
		}
	}
}


