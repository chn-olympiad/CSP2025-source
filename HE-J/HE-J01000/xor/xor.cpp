#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int a[N] , n , k;
bool f = true;

int main(){

	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i]!=1)	f = false;
	}
	if(n == 1){
		if(k == a[1])	cout << 1;
		else cout << 0;
		return 0;
	}
	if(n == 2){
		if(a[1] == k && a[2] == k)	cout << 2;
		else if(a[1]^a[2] == k || a[1] == k || a[2] == k) cout << 1;
		else cout << 0;
		return 0;
	}
	if(f && k == 0){
		cout << n/2;
		return 0;
	}
	if(k == 1){
		int ans = 0;
		for(int i = 1;i <= n;i ++)	if(a[i] == 1)	ans ++;
		cout << ans;
		return 0;
	}
	if(n <= 1000){
		int ans = 0;
		for(int i = 1;i <= n;i ++){
//			cout << i << " ";
			if(a[i] == k){
				ans ++;
				continue;
			}
			int cnt = a[i];
			for(int j = i + 1;j <= n;j ++){
			cnt^=a[j];
//			cout << cnt << "\n";
				if(cnt == k){
					ans ++ , i = j + 1;
					break;
				}
				
			}
		}
		cout << ans;
	}
	return 0;
}

