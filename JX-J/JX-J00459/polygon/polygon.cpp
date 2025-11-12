#include <bits/stdc++.h>
using namespace std;
int n,a[5010],f;
long long ans;
int main(){
	freopren("polygon.in","r",stdin);
	freopren("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(!f){
		int s=n-2;
		ans=(s*s)%998244353;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a+1,a+3+1);
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}
	}
	
	cout<<ans;
	return 0;
}
