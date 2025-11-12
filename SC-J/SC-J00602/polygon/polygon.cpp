#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
bool flag=true,flag_=true;
long long jc(long long x){
	long long cnt=1;
	for(long long i=1;i<=x;i++){
		cnt=(cnt*i)%998244353;
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i>1){
			flag=false;
		}
		if(a[i]!=1&&i>1){
			flag_=false;
		}
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(flag){
		cout<<n-2;
		return 0;
	}
	if(flag_){
		cout<<n-2;
		return 0;
	}
	cout<<jc(n);
	return 0;
}//rp++