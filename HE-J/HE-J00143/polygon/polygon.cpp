#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n,a[5010],b[5010],sum;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i = 1;i<=n;i++){
		b[i] = b[i-1] + a[i];
	}
	if(n == 3){
		if(b[3] > a[3] * 2){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			if(b[i] - b[j-1] > a[i] * 2){
				sum ++;
			}
		}
		sum %= mod;
	}
	cout << sum%mod;
	// QWQ buhui QWQ
	
	
	return 0;
}
