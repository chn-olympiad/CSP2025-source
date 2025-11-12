#include<bits/stdc++.h>
using namespace std;
int n,ans=0,bj=2,a[5005];
int ss(int mb,int cd,int syg,int jh){
	if (cd==0){
		if (jh>a[mb]){
			ans++;
			ans=ans%998244353;
		}
		return 0;
	}
	for (int i=syg+1;i<=mb-cd;i++){
		ss(mb,cd-1,i,jh+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort (a+1,a+1+n);
	if (n<=3){
		if (a[1]+a[2]>a[3])cout<<"1";
		else cout<<"0";
		return 0;
	}
	if (a[n]==1){
		int num=1;
		ans=1;
		for (int i=n-1;i>=3;i--){
			num=(num*(i+1)/(n-i))%998244353;
			ans=(ans+num)%998244353;
		}
		cout<<ans;
		return 0;
	}
	for (int i=3;i<=n;i++){
		for (int j=i-1;j>=2;j--){
			ss(i,j,0,0);
		}
	}
	cout<<ans;
	return 0;
}

