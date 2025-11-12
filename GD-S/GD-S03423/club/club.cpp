#include <bits/stdc++.h>
using namespace std;
struct node {
	int max_va, plu, w1, w2;
};
struct node1 {
	int id, va;
};
bool cmp(node a, node b) {
	return a.plu > b.plu;
}
bool cmp1(node1 a, node1 b) {
	return a.va > b.va;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	long long ans = 0;
	while(t--) {
	    int n, c[4] = {0, 0, 0, 0};
		ans = 0;
		cin >> n;
		node d[100010];	
        for(int i = 1;i <= n;i ++) {
        	node1 a[3];
        	a[1].id = 1, a[2].id = 2, a[3].id = 3;
        	cin >> a[1].va >> a[2].va >> a[3].va;
			sort(a + 1, a + 4, cmp1);
		    d[i].max_va = a[1].va, d[i].plu = a[1].va - a[2].va, d[i].w1 = a[1].id, d[i].w2 = a[2].id;
		}
		sort(d + 1, d + 1 + n, cmp);
		for(int i = 1;i <= n;i ++) {
			if(c[d[i].w1] < n / 2) {
				c[d[i].w1] ++;
				ans += d[i].max_va;
			} 
			else {
				c[d[i].w2] ++;
				ans += d[i].max_va - d[i].plu;
			}
		}
		cout << ans << endl;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
