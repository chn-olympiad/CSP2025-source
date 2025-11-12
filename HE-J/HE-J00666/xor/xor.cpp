#include<bits/stdc++.h>
using namespace std;
int n, k;
const int MAXN = 5*(1e5)+10;
int a[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x == k) ans++;
		a[i] = x;
	}           
	for(int len = 2; len <= n; len++){
		for(int i = 1; i <= n; i++){
			int j = i + len - 1;
			if(j > n) continue;
			int xor1 = a[i];
			for(int l = i+1; l <= j; l++){
				xor1 = xor1 ^ a[l];
			}
			if(xor1 == k){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
