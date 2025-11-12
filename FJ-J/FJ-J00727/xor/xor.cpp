#include<bits/stdc++.h>
using namespace std;
long long n, k, ans = 0;
int a[500005], vis[500005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == k){
			ans++;
			vis[i] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int l = 1; l <= n-i+1; l++){
			if(vis[l]) continue;
			int cnt = a[l], len = 0;
			bool f = 0;
			for(int r = l+1; r < l+i; r++){
				if(!vis[r]){
					cnt ^= a[r];
				}else{
					break;
				}
				if(cnt == k){
					ans++;
					f = 1;
					len = r-l+1;
					break;
				}
			}
			if(f){
				for(int r = l; r < l+len; r++){
					vis[r] = 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
