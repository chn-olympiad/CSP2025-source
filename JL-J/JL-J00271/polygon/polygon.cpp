#include<bits/stdc++.h>
using namespace std;
long long n,a[1000443],s=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]+a[2]>a[3]){
		cout<<"1";
		return 0;
	}else{
		cout<<"0";
	}
	cout<<s%998244353;
	return 0;
}
