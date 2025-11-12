#include<bits/stdc++.h>
using namespace std;
int t, n, ans, num1, num2, num3;
struct Node {
	int ai1, ai2, ai3;
} a[100005];
bool cmp(Node a, Node b) {
	return a.ai1 > b.ai1;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for(int T = 1; T <= t; T ++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			scanf("%d %d %d", &a[i].ai1, &a[i].ai2, &a[i].ai3);
		}
		if(n == 2) {
			int Ans = a[1].ai1 + a[2].ai2;
			ans = a[1].ai1 + a[2].ai2;
			if(Ans > ans) {
				ans = Ans;
			} 
			Ans = a[1].ai2 + a[2].ai1;
			if(Ans > ans) {
				ans = Ans;
			}
			Ans = a[1].ai2 + a[2].ai3;
			if(Ans > ans) {
				ans = Ans;
			}
			Ans = a[1].ai3 + a[2].ai1;
			if(Ans > ans) {
				ans = Ans;
			}
			Ans = a[1].ai3 + a[2].ai2;
			if(Ans > ans) {
				ans = Ans;
			}
			printf("%d\n", ans);
		} else {
			sort(a + 1, a + n + 1, cmp);
			ans = 0;
			for(int i = 1; i * 2 <= n; i ++) {
				ans += a[i].ai1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
