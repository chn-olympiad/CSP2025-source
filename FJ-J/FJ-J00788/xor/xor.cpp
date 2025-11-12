#include<bits/stdc++.h>
using namespace std;
#define N 5000
int n;
long long k, ans = 0;
long long x[N], f[N][N] = {0};
bool sp1 = true, sp2 = true;
int cnt1 = 0, cnt0 = 0;

void dfs(int l, long long cnt){
	if(l > n){
		ans = max(ans, cnt);
		return;
	}
	for(int i = l; i <= n; i++){
		if(f[l][i]==k){
			dfs(i+1, cnt+1);
		}
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &x[i]);
		if(x[i]!=1) sp1 = false;
		if(x[i]!=1&&x[i]!=0) sp2 = false;
		if(x[i]==0) cnt0++;
		else if(x[i]==1) cnt1++;
	}
	
	if(sp1 && k==0){
		cout << n/2;
		return 0;
	}
	if(sp2){
		if(k==1){
			cout << min(cnt0, cnt1);
		}
		else if(k==0){
			cout << cnt0 + cnt1/2;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(i==j) f[i][j] = x[i];
			else{
				f[i][j] = f[i][j-1] xor x[j];
			}
		}
	}
	
	dfs(1, 0);
	cout << ans;
	
	
	return 0;
	
}
