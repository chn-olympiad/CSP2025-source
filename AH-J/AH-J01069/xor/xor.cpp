#include<bits/stdc++.h>
using namespace std;
long long a[1000010], pre[1000010], sum;
long long n, k;
void dfs(int s){
	if(s > n) return;
	for(int i = s; i <= n; i++){
		for(int j = i; j <= n; j++){
			int x = pre[j] ^ pre[i - 1];
			if(x == k){
				sum++;
				dfs(j + 1);
				return;
			}
		}
	}
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	pre[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}
	dfs(1);
	cout << sum;
	return 0;
}
