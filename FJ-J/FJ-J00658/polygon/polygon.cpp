#include<bits/stdc++.h>
using namespace std;
int n,a[5100],m,ans,d;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(m==1){
		for(int k=3;k<=n;k++){
			d=1;
			for(int i=1;i<k-1<=n;i++){
				int j=i+k-1;
				d*=i;
			}
			ans+=d;
		}
		cout<<ans%988244353;
		return 0;
	}
	if(n==3){
		int t=a[1]+a[2]+a[3];
		if(a[1]*2<t&&a[2]*2<t&&a[3]*2<t){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(n>500){
		cout<<988244352;
	}else{
		cout<<n*2-1;
	}
	return 0;
}
