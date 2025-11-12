#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long ans=0;
long long jx[5005];
long long mo=998244353;
long long c(int i,int n){
	long long ansc=jx[n]/jx[i];
	ansc=ansc/jx[n-i];
	ansc%=mo;
	return ansc;
}
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	long long sum=0;
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	int maxi=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxi=max(maxi,a[i]);
	}
	if(maxi==1){
		jx[1]=1;
		for(int i=2;i<=n;i++){
			jx[i]=jx[i-1]*i;
		}
	//	cout<<jx[5000];
		for(int i=3;i<n;i++){
			ans+=c(i,n);
			ans=ans%mo;
		}
		ans++;
		cout<<ans;
		return 0;
	}
	else if(n==3){
		if(sum>(2*maxi)){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
		return 0;
		}
	}
//	else{
		
//	}
	return 0;
} 