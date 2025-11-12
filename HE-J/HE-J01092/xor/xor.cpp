#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	// 判断全为1
	int sum = 0;
	for (int i = 1; i <= n; i++) 
		if (a[i] == 1)
			++sum;
	if (sum == n) {
		printf("%d\n", (n * (n + 1)) / 2);
		return 0;
	} 
	
	//分别找两个端点
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int id = -1;
		for (int j = i; j <= n; j++) { 
			int t = 0;
			for (int l = i; l <= j; l++) {
				t = t ^ a[l];
			}
			if (t == k) { 
				++ans;
//				printf("k == %d\n", k); 
//				printf("此时的左右端点为%d %d\n", i, j);	
				id = j;//记录不重复的下一个端点 
				break;
			}
		}
		if (id != -1)
			i = id;
	} 
	printf("%d\n", ans);
	return 0;
}
