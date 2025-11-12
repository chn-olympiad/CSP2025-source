#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005];
int ton[5005];
int n;
long long ans = 0;
void dfs(int sum, int cnt, int big, int id){
	if(cnt == n){
		return ; 
	}
	if(cnt >= 3){
		if(sum>big*2){
			ans++;
			return;
		} 
	} 
	for(int i = id; i <= n; i++){
		if(ton[i])continue;
		ton[i]=1;
		big = max(big, a[i]);
		dfs(sum+a[i], cnt+1, big, i);
		ton[i]=0;
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if(n == 3){
		cout << 1;
		return 0; 
	}else if(n < 3){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	dfs(0,0,0,0);
	cout << ans;
	return 0;
}
