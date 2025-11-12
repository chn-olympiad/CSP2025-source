#include <bits/stdc++.h>
using namespace std;
int n,k,x,c,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> x;
		c = c xor x;
		if (c == k){
			ans++;
			c = 0;
		}
	}
	cout << ans;
	return 0;
}
