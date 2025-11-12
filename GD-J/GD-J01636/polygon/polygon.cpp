#include<bits/stdc++.h>
using namespace std;
long long a[5001],b[5001];
long long n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]>a[3]&&n==3){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
long long ans=0;
	for(long long i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
		if(b[i]>a[i+1]&&i>=3)ans++;
	}
	
	for(long long i=3;i<=n;i++){
		for(long long j=i-1;j>=1;j--){
			if(i-1<3)break;
			if(b[i]-a[j]>a[i]*2){
				ans++;
			}
			if(b[i]-b[j]>a[i]*2&&j!=1)ans++;
		}
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
