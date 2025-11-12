#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 210;
int n, m1, m2, m3, res;
int f[M][M >> 1][M >> 1][M >> 1];
struct Node{
	int a1, a2, a3;
}a1[N];
bool cmp(Node a, Node b){
	return a.a1 + a.a2 + a.a3 > b.a1 + b.a2 + b.a3;
}
void work1(){
	sort(a1 + 1, a1 + n + 1, cmp);
		for(int i = 1;i <= n;i++){
			if(a1[i].a1 >= a1[i].a2 && a1[i].a1 >= a1[i].a3){
				if(m1 + 1 > n >> 1){
					if(a1[i].a2 > a1[i].a3){
						m2++;
						res += a1[i].a2;
					}
					else{
						m3++;
						res += a1[i].a3;
					}
				}
				else{
					m1++;
					res += a1[i].a1;
				}
			}
			else if(a1[i].a2 >= a1[i].a1 && a1[i].a2 >= a1[i].a3){
				if(m2 + 1 > n >> 1){
					if(a1[i].a1 > a1[i].a3){
						m1++;
						res += a1[i].a1;
					}
					else{
						m3++;
						res += a1[i].a3;
					}
				}
				else{
					m2++;
					res += a1[i].a2;
				}
			}
			else{
				if(m3 + 1 > n >> 1){
					if(a1[i].a1 > a1[i].a2){
						m1++;
						res += a1[i].a1;
					}
					else{
						m2++;
						res += a1[i].a2;
					}
				}
				else{
					m3++;
					res += a1[i].a3;
				}
			}
		}
		printf("%d\n", res);
}
void work2(){
	memset(f, 0, sizeof f);
	f[1][1][0][0] = a1[1].a1;
	f[1][0][1][0] = a1[1].a2;
	f[1][0][0][1] = a1[1].a3;
	for(int i = 2;i <= n;i++){
		for(int a = 0;a <= i && a <= (i + 2) >> 1;a++){
			for(int b = 0;b <= i && b <= (i + 2) >> 1;b++){
				if(a + b > i) break;
				int c = i - a - b;
				if(c > (i + 3) >> 1) continue;
				if(a > 0) f[i][a][b][c] = max(f[i][a][b][c], f[i - 1][a - 1][b][c] + a1[i].a1);
				if(b > 0) f[i][a][b][c] = max(f[i][a][b][c], f[i - 1][a][b - 1][c] + a1[i].a2);
				if(c > 0) f[i][a][b][c] = max(f[i][a][b][c], f[i - 1][a][b][c - 1] + a1[i].a3);
			}
		}
	}
	int res = 0;
	for(int a = 0;a <= n && a <= n >> 1;a++){
		for(int b = 0;b <= n && b <= n >> 1;b++){
			int c = n - a - b;
			if(c > n >> 1) continue;
			res = max(res, f[n][a][b][c]);
		}
	}
	printf("%d\n", res);
} 
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		m1 = m2 = m3 = res = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d", &a1[i].a1, &a1[i].a2, &a1[i].a3);
		}
		if(n <= 200) work2();
		else work1();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
