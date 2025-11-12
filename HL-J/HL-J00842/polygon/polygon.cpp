#include<iostream>
#include<cstdio>
using namespace std;
long long a,n;
long long ss(long long h){
	long long ans=1;
	for(long long i=1;i<=h;i++){
		ans=ans*i%998244353;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=3;i<=n;i++){
		a+=(ss(n)/ss(i)/ss(n-i))%998244353;
	}
	cout<<a;
	return 0;
}
