#include <bits/stdc++.h>
using namespace std;
int a[5005];
long long mod = 998244353;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	long long ans = 0;
	int f = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			f = 0;
		}
	}
	sort(a+1,a+n+1);
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if((a[1] + a[2] + a[3]) > a[3] * 2){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	if(f == 1){
		int j = 2;
		for(int i = 1; i <= n; i++){
			ans += n-j;
			j++;
			ans = ans%mod;
		}
		cout << ans%mod;
		return 0; 
	}
	for(int i = 1; i <= n; i++){
		int sum = a[i];
		int k = 1;
		for(int j = i+1; j <= n; j++){
			sum+=a[j];
			k++;
			if(k >= 3 && sum > 2*a[k]){
				ans++;
			}
		}
	}
	cout << ans%mod;
	return 0;
}
