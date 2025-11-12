#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1||a[n]==2){
		cout<<(n*(n-1))/2%998244353;
		return 0;
	}else{
		if(a[n]*2<a[n-1]+a[n-2]){
			cout<<n-2;
			cout<<0;
		}else{
		}
	}
	return 0; 
} 
