#include<bits/stdc++.h>
//#undef STDIO
const int N = 20;
int n, m, a[N * N], val;
int find(int x){
	int l = 1, r = n * m, ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(a[mid] >= x){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	return ans;
}
int main(){
#ifndef STDIO
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}
	val = a[1];
	std::sort(a + 1, a + n * m + 1, std::greater<int>());
	int p = find(val);
	int x = (p - 1) / n + 1, y = (p - 1) % n + 1;
	if((x & 1) == 0) y = n - y + 1;
	printf("%d %d\n", x, y);
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}