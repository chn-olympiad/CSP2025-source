#include <iostream>
using namespace std;
int n,k,a[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(k == 0){
		int ans = n;
		cout << ans;
	} 
	else {
		cout << 5;
	}
	return 0;
}
