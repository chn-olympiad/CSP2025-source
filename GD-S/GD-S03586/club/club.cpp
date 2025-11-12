#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

int t, n, a[N][4], ans;

void my(int my_cnt, int tmp_ans, int st, int nd, int rd){
//	printf("%d %d %d %d %d\n", my_cnt, tmp_ans, st, nd, rd);
	if(my_cnt == n){
//		printf("\n");
		ans = max(tmp_ans, ans);
		return ;
	}
	if(st < n / 2){
//		printf("%d\n", a[my_cnt][1]);
		my(my_cnt + 1, tmp_ans + a[my_cnt + 1][1], st + 1, nd, rd);
	}
	if(nd < n / 2){
//		printf("%d\n", a[my_cnt][2]);
		my(my_cnt + 1, tmp_ans + a[my_cnt + 1][2], st, nd + 1, rd);
	}
	if(rd < n / 2){
//		printf("%d\n", a[my_cnt][3]);
		my(my_cnt + 1, tmp_ans + a[my_cnt + 1][3], st, nd, rd + 1);
	}
//	printf("\n");
	return ;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= 3; j ++){
				scanf("%d", &a[i][j]);
			}
		}
//		int a_ = 0, b_ = 0;
//		if(n == 2){
//			a_ = a[1][1] + a[2][2];
//			b_ = a[1][1] + a[2][3];
//			a_ = max(a_, b_);
//			b_ = a[1][2] + a[2][1];
//			a_ = max(a_, b_);
//			b_ = a[1][2] + a[2][3];
//			a_ = max(a_, b_);
//			b_ = a[1][3] + a[2][1];
//			a_ = max(a_, b_);
//			b_ = a[1][3] + a[2][2];
//			a_ = max(a_, b_);
//		}
//		if(n == 4){
//			for(int i = 1; i <= 3; i ++){
//				for(int j = 1; j <= 3; j ++){
//					for(int k = 1; k <= 3; k ++){
//						for(int l = 1; l <= 3; l ++){
//							if((i == j && j == k) || (i == j && j == l) || (i == k && k == l) || (k == j && j == l)) continue;
//							b_ = a[1][i] + a[2][j] + a[3][k] + a[4][l];
//							a_ = max(a_, b_);
//						}
//					}
//				}
//			}
//		}
		my(0, 0, 0, 0, 0);
		printf("%d\n", ans);
		ans = 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
