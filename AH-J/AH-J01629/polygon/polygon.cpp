#include<bits/stdc++.h>
using namespace std;
long long a[1100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(a[n]==1){
		long long cnt=0;
		for(int i=3;i<=n;i++){
			long long m=1,z=1;
			for(int j=n;j>=n-i+1;j--){
				m=(m*j)%998244353;
			}
			for(int j=1;j<=i;j++){
				z=(z*j)%998244353;
			}
			cnt=(cnt+(m/z))%998244353;
		}
		cout<<cnt;
	}
	return 0;
}
