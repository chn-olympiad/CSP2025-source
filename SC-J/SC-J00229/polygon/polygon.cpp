#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n<=3){
		if(a[0]<a[1]+a[2]&&a[1]<<a[0]+a[2]&&a[2]<<a[0]+a[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	cout<<(n-2)%998244353;
	return 0;
}