#include<bits/stdc++.h> 
using namespace std;
long long n,mxi,s;
long long a[5015];
long long jc(long long a){
	long long sum=1;
	for(int i=1;i<=a;i++){
		sum*=i%998244353;
	}return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxi=max(mxi,a[i]);
	}if(n<=3){
		for(int i=1;i<=n;i++){
			s+=a[i];
		}s-=mxi;
		if(s>2*mxi){
			cout<<1;
		}return 0;
	}if(mxi==1){
		for(int i=3;i<=n;i++){
			s=(s+jc(n)/(jc(i)*jc(n-i)))%998244353;
		}cout<<s;
	}
	return 0;
}

