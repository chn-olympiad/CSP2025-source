#include<bits/stdc++.h>
using namespace std;
int n,a[5005],bj=1;
long long sum=0,s[5005],m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) bj=0;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(abs(a[1]-a[2])<a[3]&&a[3]<a[1]+a[2]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(bj){
		s[0]=1; s[1]=1; s[2]=2;
		for(int i=3;i<=n;i++) s[i]=(i*s[i-1])%998244353;
		for(int i=3;i<=n;i++){
			m=( s[i] * s[n-i] ) %998244353;
			m=s[n]/m;
			sum=(sum+m)%998244353;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}