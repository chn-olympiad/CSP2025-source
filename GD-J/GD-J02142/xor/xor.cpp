#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if(k == 0){	
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				if(a[i + 1] == 1){
					ans++;
					i++;
				}
			}
			else{
				ans++;
			}
			if(i == n) break;
		}
		cout << ans;
		return 0;
	}
	
	else if(k == 1){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	
	return 0;
}

