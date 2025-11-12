#include <bits/stdc++.h>
using namespace std;
int a[5005];
int n;
int daan;
const int mod = 998244353;
void dfs(int xianzai, int zuida, int sum, int cnt){
	if(xianzai == n + 1){
		if(sum > 2 * zuida && cnt >= 3){
			daan++;
			daan %= mod;
		}
		return;	
	}
	
	dfs(xianzai + 1, max(zuida, a[xianzai]), sum + a[xianzai], cnt + 1);
	dfs(xianzai + 1, zuida, sum, cnt);
	
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0, 0, 0);
	cout << daan << endl;
} 
