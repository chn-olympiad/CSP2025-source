#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int MOD =  998244353;
int n, a[5005], sum[5005], maxs[5005];
bool flag = true, dis[5005];
int ans;
int qm(int a, int b, int p){
	int sum = 1;
	while(b){
		if(b %2) sum = (sum *a) % p;
		a = (a * a) % p;
		b /= 2;
	}
	return sum;
}
void dfs(int step, int sum, int maxn){
	if(step == n + 1){
		ans++;
		return ;
	}
	if(sum + a[step] > 2 * max(maxn, a[step])){
		dis[step] = true;	
		dfs(step + 1, sum + a[step], max(maxn, a[step]));
	}
	else dfs(step + 1, sum, maxn);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i-1] +a[i];
		maxs[i] = max(a[i], maxs[i-1]);
	}
	for(int i = 1;i <= n;i++){
		if(a[i] != 1) flag = false;
	}
	if(flag){
		cout << qm(2, n, MOD);
	}
	else{
		for(int i = 2;i <= n + 1;i++){
			dis[i-1] = true;
			dfs(i, a[i-1], a[i-1]);
		}
		cout << ans << endl;
	}
	return 0;
}