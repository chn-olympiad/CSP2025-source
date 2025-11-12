#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
int n;
long long a[5005];
long long ans = 0;
long long b[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool l = true;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] != a[i-1] && i != 1){
			l = false;
		}
		//sum[i] = sum[i-1]+a[i];
	}
	if(n < 3){
		cout<<0;
	}
	if(n == 3){
		if(a[1]+a[2] > a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	if(l == true){
		//cout<<1;
		long long cnt = 1;
		for(int i=1;i<=n;i++){
			cnt *= i;
		}
		long long c = cnt;
		for(int i=3;i<n;i++){
			//cout<<i<<endl;
			cnt = c;
			for(int j=2;j<=i;j++){
				cnt /= j;
			}
			//cout<<cnt<<endl;
			cnt = cnt%mod;
			ans += cnt;
		}
		ans = ans%mod;
		cout<<ans;
	}
    return 0;
}
