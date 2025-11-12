#include<bits/stdc++.h>
using namespace std;
int k, a[500005], b[500005], n, ans = 0;
bool vis[200005];
bool ck1(){
	for(int i = 1;i <= n;i++){
		if(a[i] != 1){
			return false;
		}
	}
	return true;
}
bool ck2(){
	for(int i = 1;i <= n;i++){
		if(a[i] != 1 && a[i] != 0){
			return false;
		}
	}
	return true;
}
void sp1(){
	ans = n / 2;
}
void sp2(){
	for(int i = 1;i <= n;i++){
		if(a[i] == 0){
			ans ++;
		}
		if((a[i] == 1 && a[i-1] == 1) && !a[i-1]){
			ans++;
			a[i] = true;
		}
	} 
}
void sp3(){
	for(int i = 1;i <= n;i++){
		if(a[i] == 1){
			ans++;
		}
	}
}
bool ck01(int x, int l){
	for(int i = x;i <= x + l - 1;i++){
		if(vis[i])
			return false;
	}
	return true;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	b[0] = 0;
	for(int i = 1;i <= n;i++){
		b[i] = b[i-1] ^ a[i];
	}
	if(k == 0 && ck1()){
		sp1();
		cout << ans;
		return 0;
	}
	if(ck2()){
		if(k == 0){
			sp2();
			cout << ans;
			return 0;
		}
		if(k == 1){
			sp3();
			cout << ans;
			return 0;
		}
	}
	for(int l = 1;l <= n;l++){
		for(int i = 1;i <= n - l + 1;i++){
			if(ck01(i,l)){
				if((b[i + l - 1] ^ b[i-1]) == k){
					for(int j = i;j <= i + l - 1;j++){
						vis[j] = true;
					}
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
