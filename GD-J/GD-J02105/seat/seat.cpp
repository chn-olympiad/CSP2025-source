#include<bits/stdc++.h>
#define fo(i, a, b) for(int i = a; i <= b; i ++)
#define fd(i, a, b) for(int i = a; i >= b; i --)

using namespace std;

const int N = 1e2 + 5;

int n, m;

int sc[N][N];

struct node {
	int id, val;
} a[N * N];//

int tot;

node Map[N][N];

int cmp(node x,node y) {
	return x.val > y.val;//
}

signed main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;//!!!!!!!!!! n*m

	fo(i, 1, n) {
		fo(j, 1, m) {
			cin >> sc[i][j];
			a[++ tot] = {(i - 1) * m + j, sc[i][j]};
		}
	}

	sort(a + 1, a + tot + 1, cmp);

	int cnt = 0;
	fo(j, 1, m) {
		if(j & 1) {
			fo(i, 1, n) {
				Map[i][j] = a[++ cnt];
			}
		} else {
			fd(i, n, 1) {
				Map[i][j] = a[++ cnt];
			}
		}
	}

	fo(i, 1, n) {
		fo(j, 1, m) {
//			cout << Map[i][j].val << " ";
			if(Map[i][j].id == 1) {
				cout << i << " " << j << "\n";
				return 0;
			}
		}
//		cout << "\n";
	}


	return 0;
}

