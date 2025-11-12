#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct {
	int d1;
	int d2;
	int d3;
} Member;

int t;
int n;
Member a[100005];
Member solution[4][100005]; // 每个部门成员
int solution_index1 = 0;
int solution_index2 = 0;
int solution_index3 = 0;
int init_index1 = 0;
int init_index2 = 0;
int init_index3 = 0;
int solution_sum[4]; // 每个部门满意度和 

int check() {
	if (solution_index1 > n / 2) {
		return 1;
	}
	if (solution_index2 > n / 2) {
		return 2;
	}
	if (solution_index3 > n / 2) {
		return 3;
	}
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	// Main Code
	scanf("%d", &t);
	while (t--) {
		solution_index1 = 0;
		solution_index2 = 0;
		solution_index3 = 0;
		
		solution_sum[1] = 0;
		solution_sum[2] = 0;
		solution_sum[3] = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].d1, &a[i].d2, &a[i].d3);
		}
		for (int i = 1; i <= n; i++) { 
			int max_expect = 0;
			int to = -1;
			if (a[i].d1 > max_expect) {
				max_expect = a[i].d1;
				to = 1;
			}
			if (a[i].d2 > max_expect) {
				max_expect = a[i].d2;
				to = 2;
			}
			if (a[i].d3 > max_expect) {
				max_expect = a[i].d3;
				to = 3;
			}
			// 获得最大期望值后
			// 把成员加到对应部门 
			if (to == 1) {
				solution_index1++;
				solution[1][solution_index1].d1 = a[i].d1;
				solution[1][solution_index1].d2 = a[i].d2;
				solution[1][solution_index1].d3 = a[i].d3;
				solution_sum[to] += max_expect;	
			}
			if (to == 2) {
				solution_index2++;
				solution[to][solution_index2].d1 = a[i].d1;
				solution[to][solution_index2].d2 = a[i].d2;
				solution[to][solution_index2].d3 = a[i].d3;
				solution_sum[to] += max_expect;
				
			}
			if (to == 3) {
				solution_index3++;
				solution[to][solution_index3].d1 = a[i].d1;
				solution[to][solution_index3].d2 = a[i].d2;
				solution[to][solution_index3].d3 = a[i].d3;
				solution_sum[to] += max_expect;
				
			}
		}
		
		// 接下来开始处理有部门成员大于n/2的情况
		// 因为要让满意度尽可能大
		// 所以要让delta尽可能地小
		init_index1 = solution_index1;
		init_index2 = solution_index2;
		init_index3 = solution_index3;
		while (check() != 0) {
//			printf("SOL_INDEX_1 %d\n", solution_index1);
//			printf("SOL_INDEX_2 %d\n", solution_index2);
//			printf("SOL_INDEX_3 %d\n", solution_index3);
//			printf("CHECK: %d\n", check());
			int ret_val = check();
			int min_delta = 9114514;
			int index = 0;
			int option = 0;
//			printf("option_init:%d\n", option);
			if (ret_val == 1) {
				//当1很多的时候 
				for (int i = 1; i <= init_index1; i++) {
					int val1 = solution[1][i].d1 - solution[1][i].d2;
					int val2 = solution[1][i].d1 - solution[1][i].d3;
					if (val1 < val2) {
						if (val1 < min_delta) {
							min_delta = val1;
							index = i;
							option = 2;
						}
					} else {
						if (val2 < min_delta) {
							min_delta = val2;
							index = i;
							option = 3;
						}
					} 
				}
//				printf("option:%d\n", option);
				// 以上代码得到了损失最小的方案
				// 开始移动成员
				solution_index1--;
				if (option == 2) {
					solution_index2++;
					// 修改sum数组
					// 减去slot1 加上slot2 
					solution_sum[1] -= solution[1][index].d1;
					solution_sum[2] += solution[1][index].d2;
//					solution[2][solution_index2] = solution[1][index];
				}
				if (option == 3) {
					solution_index3++;
					// 修改sum数组
					// 减去slot1 加上slot3 
					solution_sum[1] -= solution[1][index].d1;
					solution_sum[3] += solution[1][index].d3;
//					solution[3][solution_index2] = solution[1][index];
				}
				// 清除原有位置
				solution[1][index].d1 = 9915514; 
			}
			if (ret_val == 2) {
				// 当2很多的时候 
				for (int i = 1; i <= init_index2; i++) {
					int val1 = solution[2][i].d2 - solution[2][i].d1;
					int val2 = solution[2][i].d2 - solution[2][i].d3;
					if (val1 < val2) {
						if (val1 < min_delta) {
							min_delta = val1;
							index = i;
							option = 1;
						}
					} else {
						if (val2 < min_delta) {
							min_delta = val2;
							index = i;
							option = 3;
						}
					} 
				}
//				printf("option:%d\n", option);
				// 以上代码得到了损失最小的方案
				// 开始移动成员
				solution_index2--;
				if (option == 1) {
					solution_index1++;
					// 修改sum数组
					// 减去slot2 加上slot1 
					solution_sum[2] -= solution[2][index].d2;
					solution_sum[1] += solution[2][index].d1;
//					solution[2][solution_index2] = solution[1][index];
				}
				if (option == 3) {
					solution_index3++;
					// 修改sum数组
					// 减去slot2 加上slot3 
					solution_sum[2] -= solution[2][index].d2;
					//printf("index: %d | d2:%d\n", index, solution[2][index].d2);
					solution_sum[3] += solution[2][index].d3;
//					solution[2][solution_index2] = solution[1][index];;
				}
				// 清除原有位置
				solution[2][index].d2 = 9915514; 
			}
			if (ret_val == 3) {
				// 当3很多的时候 
				for (int i = 1; i <= init_index3; i++) {
					int val1 = solution[3][i].d3 - solution[3][i].d1;
					int val2 = solution[3][i].d3 - solution[3][i].d2;
					if (val1 < val2) {
						if (val1 < min_delta) {
							min_delta = val1;
							index = i;
							option = 1;
						}
					} else {
						if (val2 < min_delta) {
							min_delta = val2;
							index = i;
							option = 2;
						}
					} 
				}
//				printf("option:%d\n", option);
				// 以上代码得到了损失最小的方案
				// 开始移动成员
				solution_index3--;
				if (option == 1) {
					solution_index1++;
					// 修改sum数组
					// 减去slot3 加上slot1 
					solution_sum[3] -= solution[3][index].d3;
					solution_sum[1] += solution[3][index].d1;
//					solution[2][solution_index2] = solution[1][index];
				}
				if (option == 2) {
					solution_index2++;
					// 修改sum数组
					// 减去slot3 加上slot2
					solution_sum[3] -= solution[3][index].d3;
					solution_sum[2] += solution[3][index].d2;
//					solution[2][solution_index2] = solution[1][index];;
				}
				// 清除原有位置
				solution[2][index].d2 = 9915514; 
			}
//			printf("SOL_SUM1 %d\n", solution_sum[1]);
//			printf("SOL_SUM2 %d\n", solution_sum[2]);
//			printf("SOL_SUM3 %d\n", solution_sum[3]);
//			printf("\n");
		} 
		printf("%d\n", solution_sum[1] + solution_sum[2] + solution_sum[3]);
	}
	return 0;
} 
