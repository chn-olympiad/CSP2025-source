#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k;
int l1 = 1, l2;
int f = 3;
int a[N], ans = 1;
void func() {
	if(k > 1)
		int l2 = k - l1;
	else if(k == 1)
		f = 1;
	else
		f = 0;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	func();
	cin >> a[0];
	ans = a[0];
	for(int i = 1; i < n; i ++){
		cin >> a[i]; 
	}
	if(!f)
		cout << 1;
	else if(f == 3){
		for(int i = l1 - 1; i < l2; i ++) {
			ans ^= a[i]; 
		}
		cout << ans;
	}
	else {
		for(int i = 1; i < n; i ++)
			ans += a[i];
		cout << ans; 
	}
	return 0;
} 
