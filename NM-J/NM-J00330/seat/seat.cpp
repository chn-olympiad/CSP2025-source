#include<bits/stdc++.h>
using namespace std;
int a[120];
int n, m, i, j;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int len = n * m;
	for(i = 1; i <= len; i ++){
		scanf("%d", &a[i]);
	}
	int r = a[1];
	sort(a+1, a + len + 1, greater<int>());
	//for(i = 1; i <= len; i ++)cout<<a[i]<<' ';cout<<endl;
	for(i = 1; i <= m; i ++){
		for(j = 1; j <= n; j ++){
			//计算当前编号
			int num = (i - 1) * n + j;
			//printf("%d %d %d %d\n", i, j, num, a[num]);
			int k = j;
			if(i % 2 == 0)k = n - j + 1;
			if(a[num] == r){
				printf("%d %d\n", i, k);
				return 0;
			}
		}
	}
	return 0;
}
