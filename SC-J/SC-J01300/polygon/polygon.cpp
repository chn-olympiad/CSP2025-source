#include<bits/stdc++.h>
using namespace std;
long long n,a[100000],b[1000000],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(b[3]>a[3]*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		if(b[i]<=a[i]*2){
			continue;
		}
		if(i==n && b[i]>a[i]*2){
			ans++;
			continue;
		}
		if(i==n-1){
			for(int j=1;j<=n-2;j++){
				if(b[i]-a[j]>a[i]*2){
					ans++;
				}
			}
		}
		for(int j=1;j<=i-1;j++){
			if(b[i]-a[j]>a[i]*2){
				ans++;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}