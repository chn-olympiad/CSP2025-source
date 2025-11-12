#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[5005];
int d[5005],gs,c[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=5001;j>=2;j--){
			c[min(j+a[i-1],5001)]+=c[j];
			c[min(j+a[i-1],5001)]%=mod;
		}
		for(int j=1;j<=i-2;j++){
			c[min(5001,a[j]+a[i-1])]++;
			c[min(5001,a[j]+a[i-1])]%=mod;
		}
		for(int j=5001;j>a[i];j--){
			int ls=min(j+a[i],5001);
			d[ls]+=c[j];
			d[ls]%=mod;
		}
	}
	for(int i=3;i<=5001;i++) ans+=d[i],ans%=mod;
	cout<<ans;
	return 0;
}

