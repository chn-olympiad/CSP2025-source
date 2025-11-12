#include <bits/stdc++.h>
using namespace std;
int n,a[5050],sum[5050];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool b = true;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		sum[i] = sum[i - 1] + a[i];
		if(a[i] != 1) b = false;
	} 
	if(n == 3){
		int timp = max(a[1],max(a[2],a[3]));
		if(sum[3] > timp) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else if(b){
		for(int j = 3;j <= n;j++){
			long long chenji = 1,chen = 1;
			for(int k = n;k >= n - j + 1;k--){
				chenji *= k;
			}
			for(int t = 1;t <= j;t++){
				chen *= t;
			}
			ans += chenji/chen;
		}
		cout<<ans%998244353<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
