#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
const int MAXM = 10010;
const int MOD = 998244353;
int a[MAXN];
int n, cnt = 0;
long long jc[MAXM];
long long C(int x, int y){
	if (x == y) return 1;
	//printf("x:%d, y:%d, y-x:%d, jc[y]:%d, jc[y-x]:%d\n", x, y, y-x, jc[y], jc[y-x]);
	
	return jc[y]/jc[y-x];
}
long long dfs(long long maxn, long long a_sum, long long a_size, long long longside){
	//printf("maxn:%d, a_sum:%d, a_size:%d, longside:%d\n", maxn, a_sum, a_size, longside);
	long long cnt = 0;
	if (a_sum > maxn*2){
		for (int i = 1; i <= n-longside; i++){
			cnt = (C(i, n-longside) + cnt)%MOD;
		}
		//printf("cnt:%d\n", cnt);
		return cnt+1;
	}
	for (int i = longside+1; i <= n; i++){
		//printf("cnt:%d\n", cnt);
		cnt = (cnt + dfs(maxn, a_sum+a[i], a_size+1, i))%MOD;
	}
	if (longside == n){
		return 0;
	}
	return cnt;
}
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	jc[1] = 1;
	for (int i = 2; i <= MAXM; i++){
		jc[i] = (jc[i-1]*i)%MOD;
	}
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1, cmp);
	long long cnt = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			for (int k = j+1; k <= n; k++){
				//printf("i:%d, j:%d, k:%d\n", i, j, k);
				cnt = (cnt + dfs(a[i], a[i]+a[j]+a[k], 3, k))%MOD;
			}
		}
	}
	cout << cnt;
	return 0;
} 
