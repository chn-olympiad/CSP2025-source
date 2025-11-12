#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while(t --) {
		int n, c1 = 0, c2 = 0, c3 = 0;
		long long ans = 0;
		int a[100010][3], d[100010], l = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		for(int i = 0; i < n; i ++) {
			int maxn = max(max(a[i][0], a[i][1]), a[i][2]);
			ans += maxn;
	 		if(maxn == a[i][0]) c1 ++;
			if(maxn == a[i][1]) c2 ++;
			if(maxn == a[i][2]) c3 ++;
		}
		if(c1 > n / 2) 
			for(int i = 0; i < n; i ++) 
				if(max(max(a[i][0], a[i][1]), a[i][2]) == a[i][0]) d[l ++] = a[i][0] - max(a[i][1], a[i][2]);	
		if(c2 > n / 2) 
			for(int i = 0; i < n; i ++) 
				if(max(max(a[i][0], a[i][1]), a[i][2]) == a[i][1]) d[l ++] = a[i][1] - max(a[i][0], a[i][2]);	
		if(c3 > n / 2) 
			for(int i = 0; i < n; i ++) 
				if(max(max(a[i][0], a[i][1]), a[i][2]) == a[i][2]) d[l ++] = a[i][2] - max(a[i][0], a[i][1]);	
				
		sort(d, d + l);
		int c = max(max(c1, c2), c3);
		for(int i = 0; i < c - n / 2; i ++) ans -= d[i];
		cout << ans << endl;
	}
}
