#include<bits/stdc++.h>
using namespace std;
const int mod = 988244353;
int n, a[5050], i, j, as[5050];
bool used[5050];
bool isall1 = 1;
int dfs(int k){
	used[k] = 1;
	int s, sum, maxx, sn;
	for(i = 1; i <= n; i ++){
		s += used[i] * a[i];
		sn += used[i];
		maxx = max(maxx, used[i] * a[i]);
		if(s > maxx * 2 && sn >= 3)sum = (sum + 1) % mod;
	}
	for(i = k+1; i <= n; i ++)sum += dfs(i);
	used[k] = 0;
	return sum;
}
int main(){
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		if(a[i] != 1)isall1 = 0;
	}
	if(isall1){
		int n2 = 1;
		for(i = 1; i <= n - 3; i ++)n2 = (n2 * 2) % mod;
		printf("%d", n2);
		return 0;
	}
	cout<<dfs(1);
	return 0;
}
