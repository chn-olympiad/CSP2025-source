#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],m,v;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
		v+=a[i];
	}if(n==3){
		if(v-2*m>0){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<n-2;
	} 
	return 0;
}
