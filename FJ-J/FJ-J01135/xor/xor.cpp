#include<bits/stdc++.h>
using namespace std;
int a[500010] = {};
int ans = 0;
void op(int n, int k, int b){
	if(b == k){
		ans++;
		return;
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(b==-1){
			b = a[i];
		}
		op(n, k, b >> a[i]);
	}
}
int main(){
	freopen("xor1.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	op(n, k, -1);
	cout << ans;
	return 0;
}
