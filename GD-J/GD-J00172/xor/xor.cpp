#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, k, a[N], ans;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++){
		if(a[i] && k || !a[i] && !k) ans++;
		if(a[i] && a[i + 1] && !k) ans++, i++;
	}
	
	cout << ans;
	
	return 0;
} 
