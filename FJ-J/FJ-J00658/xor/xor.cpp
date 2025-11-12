#include<bits/stdc++.h>
using namespace std;
int n,k,a[110000],s0,s1;
int f(bool x,bool y){
	return x|y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			s0++;
		}else if(a[i]==1){
			s1++;
		}
	}
	if(k==0){
		cout<<max(s0,s1/2);
		return 0;
	}else if(k==1){
		cout<<s1;
		return 0;
	}
	cout<<2*n-1;
	return 0;
}
