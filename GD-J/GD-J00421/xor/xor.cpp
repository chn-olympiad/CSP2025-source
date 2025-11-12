#include<bits/stdc++.h>
using namespace std;
int n, k, a[500001], f, t, cnt;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1) f = max(f, 1);
		if(a[i] > 1) f = 2;
	} 
	if(f == 0){
		cout << n / 2;
	}
	if(f == 1){
		t = -1;
		for(int i = 1; i <= n; i++){
			if(t == -1){
				t = a[i];
				if(t == k){
					cnt++;	
					t = -1;
				} 
			}
			else{
				t ^= a[i];
				if(t == k){
					cnt++;
					t = -1;
				} 
			} 
		}
		if(t != -1) cnt--;
		cout << cnt;
	}
	
	return 0;
}
