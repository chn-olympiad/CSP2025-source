#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 50;
int a[N], b[N], ans;
int n, k;
void dfs(int cnt){
	ans = max(cnt, ans);
	for(int i = 1; i <= n; i++){
		int sum = a[i];
		for(int j = i; j <= n; j++){
			if(j != i)
			sum = (sum ^ a[j]);
			if(b[j] == 1){
				i = j + 1;
				break;
			} 
			if(sum == k){
//				cout << " | " << j << " " << i << " | ";
				for(int k = i; k <= j; k++) b[k] = 1;
				dfs(cnt+1);
				for(int k = i; k <= j; k++) b[k] = 0;
			}
		}	
	}
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 	cin >> n >> k;
 	int num0=0, num1=0;
 	for(int i = 1; i <= n; i++){
 		cin >> a[i];
 		if(a[i] == 0) num0++;
 		if(a[i] == 1) num1++;
	} 
	if(k == 0){
		cout << num0;
		return 0;	
	} else if(k == 1){
		cout << num1;
		return 0;
	}
	dfs(0);
	cout << ans;
	return 0;
}