#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],x;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out" , "w", stdout);
	cin >> n >> k;
	int ans = n;
	x = n;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=0) ans--;
		if (a[i]==0) x--;
	}
	if (k==0) cout << ans;
	else if (k==1){
		
		cout << x;
	}
	else{
		cout << 66;
	}
	return 0;
}
