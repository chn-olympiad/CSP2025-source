#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],fa=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]!=1)fa=0;
	}
	if(fa==1){
		if(k==0) cout << n/2;
		else cout << n;
	}else{
		int ans = 0,xr=0;
		for(int i = 1;i <= n;i++){
			xr = (a[i]^xr);
			if(xr==k){
				ans++;
				xr=0;
			}
		}
		cout << ans;
	}
	return 0;
}
