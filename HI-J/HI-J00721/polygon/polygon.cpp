#include<bits/stdc++.h>
using namespace std;


int ans = 0, dp[5001][5001] = {{}}, l[5001] = {}, l_[5001] = {}, n;
void DP(int max, int max_){
	if( == ){
		if() ans ++;
	}
	for(int i = 3; i < max_; i++) DP(, i);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> l[i];
		l_[l[i]] ++;
	}
	sort(l + 1, l + n + 1);
	DP(l[n], n);
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
