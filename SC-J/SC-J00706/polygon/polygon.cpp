#include<bits/stdc++.h>
using namespace std;
int n,a[5211],ma=INT_MIN,s;
int main(){
	freoprn("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		s+=a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(s>ma*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(ma==1){
		cout<<n-2;
	}
	return 0;
}