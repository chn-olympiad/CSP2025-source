// CSP 2025 RP++
/* \gcx ls/ \gcx ls/*/ 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<int, int> 
#define N 1010

int n, m;
struct node {
	int num, idx;
} a[110], seats[110][100]; 

bool cmp(node a, node b) {
	return a.num > b.num;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].num;
		a[i].idx = i;
	}
	
	sort(a + 1, a + (n * m) + 1, cmp);
	
	int IDXN = 1;
	
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				seats[i][j] = a[IDXN];
				IDXN++;
			}
		} else {
			for (int j = m; j >= 1; j--) {
				seats[i][j] = a[IDXN];
				IDXN++;
			}			
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (seats[i][j].idx == 1) {
				cout << i << ' ' << j << endl;
				break;
			}
		}
		cout << endl;

	}
	
	return 0;
}
