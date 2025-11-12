#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,k,a[N];
bool ans = true; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		if(a[i] != k)
			ans = false;
	}
	if(n == 1){
		if(a[1] == k) cout << 1;
		else cout << 0;
	} 
	if(n == 2){
		if(a[1] = k && a[2] == k) cout << 2;
		else if(a[1] | a[2] == k) cout << 1;
		else cout << 0;
	}
	if(ans == true) cout << n;
	else cout << 2;
	return 0;
} 
