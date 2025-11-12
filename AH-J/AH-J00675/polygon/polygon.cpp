#include <bits/stdc++.h>
using namespace std;
int n,a[5005],f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(!f) cout<<n;
	else{
		if(a[1]+a[2]>a[3] && a[2]+a[3]>a[1] && a[1]+a[3]>a[2])cout<<1;
		else cout<<0;
	}
	return 0;
}
