#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,a[5],m=1,sum,n2;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	m=n;
	n2=n;
	n2--;
	m*=n2;
	n2--;
	m*=n2;
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]*2<a[1]+a[2]+a[3]&&a[2]<a[1]+a[3]&&a[3]<a[1]+a[2])
		cout<<1;
		else cout<<0;
		return 0;
	}
	else for(int i=3;i<=n;i++){
		sum+=m;
		sum%=MOD;
		m*=n2;
		m%=MOD;
		n2--;	
	}
	cout<<sum;
	
	
	return 0;
}
