#include <bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005],ma;
long long sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		ma=max(ma,a[i]);
	}
	if (n==3){
		if (ma*2>=a[1]+a[2]+a[3]){
			cout << 0;
		}
		else{
			cout << 1;
		}
	}
	else{
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++){
			f[i]=f[i-1]+1;
			for (int j=1;j<=i;j++){
				if (a[j]>=(a[i]-1)/2){
					a[i]=1+f[j-1];
					break;
				}
			}
			sum=(a[i]+sum)%998244353;
		}
		cout << (sum+1)/2;
	}
	return 0;
}
