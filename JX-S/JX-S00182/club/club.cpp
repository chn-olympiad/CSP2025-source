#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;

struct club{
	int x, y, z;
}a[MAXN];
bool check(int m, int n){
	return m <= n / 2;
}
bool check1(int m, int n){
	return m < n / 2;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		bool t1[MAXN], t2[MAXN], t3[MAXN];
		memset(t1, 0, sizeof(t1));
		memset(t2, 0, sizeof(t2));
		memset(t3, 0, sizeof(t3));
		int n;
		scanf("%d", &n);
		int c1 = 0, c2 = 0, c3 = 0, ans = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			if(a[i].x == a[i].y && a[i].x == a[i].z) {
				c1++;
				ans += a[i].x;
			}
			else if(a[i].x >= a[i].y && a[i].x >= a[i].z) {
				c1++;
				ans += a[i].x;
			}
			else if(a[i].y >= a[i].x && a[i].y >= a[i].z) {
				c2++;
				ans += a[i].y;
			}
			else if(a[i].z >= a[i].x && a[i].z >= a[i].y) {
				c3++;
				ans += a[i].z;
			}
		}
		
		while(!check(c1, n)){
			int cnt = INT_MAX, f = 0, k;
			for(int i = 1; i <= n; i++){
				if(t1[i]) continue;
				if(a[i].x - a[i].y >= 0 && check1(c2, n)){
					if(a[i].x - a[i].y < cnt) {
						cnt = a[i].x - a[i].y;
						f = 2;
	                    k = i;
					}
				}
				if(a[i].x - a[i].z >= 0 && check1(c3, n)){
					if(a[i].x - a[i].z < cnt && a[i].z) {
						cnt = a[i].x - a[i].z;
						f = 3;
						k = i;
					}
				}
			}
			t1[k] = 1;
			c1--;
			ans -= cnt;
			if(f == 2) c2++;
			else if(f == 3) c3++;
		}
		while(!check(c2, n)){
			int cnt = INT_MAX, f = 0, k;
			for(int i = 1; i <= n; i++){
				if(t2[i]) continue;
				if(a[i].y - a[i].x > 0 && check1(c1, n)){
					if(a[i].y - a[i].x < cnt) {
						cnt = a[i].y - a[i].x;
						f = 1;
						k = i;
					}
				}
				if(a[i].y - a[i].z >= 0 && check1(c3, n)){
					if(a[i].y - a[i].z < cnt && a[i].z) {
						cnt = a[i].y - a[i].z;
						f = 3;
						k = i;
					}
				}	
			}
			t2[k] = 1;
			c2--;
			ans -= cnt;
			if(f == 1) c1++;
			else if(f == 3) c3++;
		}
		while(!check(c3, n)){
			int cnt = INT_MAX, f = 0, k;
			for(int i = 1; i <= n; i++){
				if(t3[i]) continue;
				if(a[i].z - a[i].y > 0 && check1(c2, n)){
					if(a[i].z - a[i].y < cnt) {
						cnt = a[i].z - a[i].y;
						f = 2;
						k = i;
					}
				}
				if(a[i].z - a[i].x > 0 && check1(c1, n)){
					if(a[i].z - a[i].x < cnt) {
						cnt = a[i].z - a[i].x;
						f = 1;
						k = i;
					}
				}
			}
			t3[k] = 1;
			c3--;
			ans -= cnt;
			if(f == 1) c1++;
			else if(f == 2) c2++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
