#include<bits/stdc++.h>
using namespace std;
long long n ,  m , a[5005] , sum , ans;
void dfs(long long i , long long now , long long ma){
	if(i == n){
		if(now + a[i] > 2 * max(ma , a[i])) ans++;
		if(now > 2 * ma) ans++;
		return;
	}else{
		dfs(i + 1 , now + a[i] , max(ma , a[i]));
		dfs(i + 1 , now , ma);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	dfs(1 , 0 , 0);
	cout << ans;
	return 0;
}

