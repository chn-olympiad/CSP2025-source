#include<bits/stdc++.h>
using namespace std;
int a[5005][5005][2];
long long jc(int n,int m){
	long long ans=1;
	if(n-m>m){
		for(int i=n;i>n-m;i--){ans*=i;}
		for(int i=2;i<=m;i++){ans/=i;}
	}
	else{
		for(int i=n;i>m;i--){ans*=i;}
		for(int i=2;i<=n-m;i++){ans/=i;}
	}
	return ans%998244353;
}
long long a(int n){
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=jc(n,i);
		ans%=998244353;
	}
	return ans;
} 
int main(){
	int n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){cout<<0;}
	else{cout<<a(n);}
	return 0;
}