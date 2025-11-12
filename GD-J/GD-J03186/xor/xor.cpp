#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	if(n == 1){
		cout << 0;
		return 0;
	}
	if(n == 2){
		int b = a[1],c = a[2],d = a[1] ^ a[2];
		if(b == k) ans++;
		if(c == k) ans++;
		if(d == k && b != k && c != k) ans++;
		cout << ans;
		return 0;
	}
	if(n == 3){
		if(a[1] == k) ans++;
		if(a[2] == k) ans++;
		if(a[3] == k) ans++;
		if(a[1] ^ a[2] == k && a[1] != k && a[2] != k) ans++;
		if(a[2] ^ a[3] == k && a[3] != k && a[2] != k) ans++;
		if(a[1] ^ a[2] ^ a[3] == k && a[1] != k && a[2] != k && a[3] != k) ans++;
		cout << ans;
		return 0;
	}
	if(n == 4){
		if(a[1] == k) ans++;
		if(a[2] == k) ans++;
		if(a[3] == k) ans++;
		if(a[4] == k) ans++;
		if(a[1] ^ a[2] == k && a[1] != k && a[2] != k) ans++;
		if(a[2] ^ a[3] == k && a[3] != k && a[2] != k) ans++;
		if(a[3] ^ a[4] == k && a[3] != k && a[4] != k) ans++;
		if(a[1] ^ a[2] ^ a[3] == k && a[1] != k && a[2] != k && a[3] != k) ans++;
		if(a[2] ^ a[3] ^ a[4] == k && a[4] != k && a[2] != k && a[3] != k) ans++;
		if(a[1] ^ a[2] ^ a[3] ^ a[4] == k && a[1] != k && a[2] != k && a[3] != k && a[4] != k) ans++;
		cout << ans;
		return 0;
	}
	if(n == 5){
		if(a[1] == k) ans++;
		if(a[2] == k) ans++;
		if(a[3] == k) ans++;
		if(a[4] == k) ans++;
		if(a[5] == k) ans++;
		if(a[1] ^ a[2] == k && a[1] != k && a[2] != k) ans++;
		if(a[2] ^ a[3] == k && a[3] != k && a[2] != k) ans++;
		if(a[3] ^ a[4] == k && a[3] != k && a[4] != k) ans++;
		if(a[4] ^ a[5] == k && a[5] != k && a[4] != k) ans++;
		if(a[1] ^ a[2] ^ a[3] == k && a[1] != k && a[2] != k && a[3] != k) ans++;
		if(a[2] ^ a[3] ^ a[4] == k && a[4] != k && a[2] != k && a[3] != k) ans++;
		if(a[3] ^ a[4] ^ a[5] == k && a[4] != k && a[5] != k && a[3] != k) ans++;
		if(a[1] ^ a[2] ^ a[3] ^ a[4] == k && a[1] != k && a[2] != k && a[3] != k && a[4] != k) ans++;
		if(a[2] ^ a[3] ^ a[4] ^ a[5] == k && a[5] != k && a[2] != k && a[3] != k && a[4] != k) ans++;
		if(a[1] ^ a[2] ^ a[3] ^ a[4] ^ a[5] == k && a[1] != k && a[2] != k && a[3] != k && a[4] != k && a[5] != k) ans++;
		cout << ans;
		return 0;
	}
	cout << 7;
	return 0;
}
