#include<bits/stdc++.h>
using namespace std;
int a[500005], cnt[500005]; 
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[i] = 0;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == k && cnt[i] == 0){
			ans++;
			cnt[i] = 1;
		} else if(cnt[i + 1] == 0 && a[i] ^ a[i + 1] == k){
			ans++;
			cnt[i + 1] = 1;
		}
	}
	cout << ans;
	return 0;
} 
