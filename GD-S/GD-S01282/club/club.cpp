//F
#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a, b, c;
}a[100005];
int t, n, ans;
void dfs(int i, int x, int y, int z, int ra, int rb, int rc){
	if(i == n + 1){
		ans = max(ans, x + y + z);
		return;
	}
	if(ra < n / 2)dfs(i + 1, x + a[i].a, y, z, ra + 1, rb, rc);
	if(rb < n / 2)dfs(i + 1, x, y + a[i].b, z, ra, rb + 1, rc);
	if(rc < n / 2)dfs(i + 1, x, y, z + a[i].c, ra, rb, rc + 1);
}
bool cmp(stu A, stu B){
	return A.a > B.a;
}
bool cmp2(stu A, stu B){
	return abs(A.a - A.b) < abs(B.a - B.b);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		bool flaga = 0, flagb = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			flaga |= a[i].b | a[i].c;
			flagb |= a[i].c;
		}
		ans = 0;
		if(!flaga){
			stable_sort(a + 1, a + n + 1, cmp);
			for(int i = 1; i <= ans / 2; i++)ans += a[i].a;
		}
		else if(!flagb){
			stable_sort(a + 1, a + n + 1, cmp2);
			int t1 = 0, t2 = 0, i = 1;
			for(i = 1; i <= n; i++){
				if(a[i].a > a[i].b){
					t1++, ans += a[i].a;
				}
				else{
					t2++, ans += a[i].b;
				}
			}
			i = 1;
			if(t1 > t2){
				while(t1 > t2){
					if(a[i].a > a[i].b){
						t1--, t2++, ans -= a[i].a - a[i].b;
					}
					i++;
				}
			}
			if(t1 < t2){
				while(t1 < t2){
					if(a[i].a <= a[i].b){
						t1++, t2--, ans -= a[i].b - a[i].a;
					}
					i++;
				}
			}
		}
		else if(n <= 20)dfs(1, 0, 0, 0, 0, 0, 0);
		else{
			for(int i = 1; i <= n; i++)ans += max(max(a[i].a, a[i].b), a[i].c);
		}
		printf("%d\n", ans);
	}
	return 0;
} 
//U
