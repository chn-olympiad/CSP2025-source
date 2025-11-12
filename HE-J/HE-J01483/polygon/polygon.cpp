#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3) {
		if(a[1]+a[2]>a[3]){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	if(a[n]<=1) {
		for(int i=3;i<=n;i++){
			long long k1=1,k2=1;
			for(int j=1;j<=i;j++){
				k1*=(n-j+1);
				k2*=j;
				k1/=k2;
				k2=1;
				k1%=998244353;
			}
			ans+=k1;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
