#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;++i) cin >> a[i];
	int ans = 0,i = 1;
	while(i <= n){
		if(a[i] == k){
			ans++;
//			cout << i << "(1)\n";
		} 
		else if(a[i + 1] == (a[i] ^ k)){
//			cout << a[i] << " " << a[i + 1] << " " << (a[i] ^ k) << "(2)\n";
			ans++,i++;
		}
		i++;
	}
	cout << ans << "\n"; 
	return 0;
}
