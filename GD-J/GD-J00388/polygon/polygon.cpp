#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],f[5005];
const int MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]; 
	}	
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){ 
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=3;i<=n;i++){
		f[i]=f[i-1]%MOD;
		if (sum[i-1]>a[i]*2){
			for (int j=1;j<=i;j++){
				if (sum[j]>a[i]*2){
					for (int k=j;k<=i;k++){
						f[i]+=k*k%MOD;
					}
				}
			}
		}
	} 
	cout<<f[n];
	return 0; 
}
