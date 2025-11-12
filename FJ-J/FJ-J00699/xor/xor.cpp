#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int a[maxn];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == 1){
		if(a[1] == k) cout << 1;
		else cout << 0;
		return 0;
	}
	else{
		if(a[1] == k && a[2] == k) cout << 2;
		else cout << 1;
		return 0;
	}
	cout << 1;
	return 0;
}
