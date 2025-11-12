//long long + scanf!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
int n, a[10001][3], ip = 0, j = 0, k = 0, b[10001];
int maxx = 0;
int maxn = 0;
void p (int o) {
	//cout << o << " " << ip << " " << j << " " << k << " " << maxx << endl;
	if (o == n) {
		maxn = max(maxn, maxx);
		return;
	}
	
	if (++ip <= n / 2) {
		maxx += a[o][0];
		
		p(o + 1);
		maxx -= a[o][0];
		
		
	}
	ip --;
	if (++j <= n / 2) {
		maxx += a[o][1];
		
		p(o + 1);
		maxx -= a[o][1]; 
		
	}
	j --;
	if (++k <= n / 2) {
		maxx += a[o][2];
		
		p(o + 1);
		maxx -= a[o][2];
		
	}
	k --;
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t;
	cin >> t;
	while(t--) {
		scanf("%d", &n);
		bool spea = 1, speb = 1;
		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
			if (a[i][2] != 0) {
				speb = 0;
			}
			if (a[i][2] != 0 || a[i][1] != 0) {
				spea = 0;
			}
			if(spea) {
				b[i] = a[i][0];
			}
		}
		//cout << endl << n << endl;
		ip = 0, j = 0, k = 0;
		maxn = maxx = 0;
		if(spea) {
			sort(b, b + n);
			for (int i = n; i >= n / 2; i--) {
				maxn += b[i];
				//cout << i << " " << a[i][0] << endl;
			}
		}else if (speb) {
			p(0);
		}else {
			p(0);
		}
		
		cout << maxn << endl;
	}
	return 0;
}