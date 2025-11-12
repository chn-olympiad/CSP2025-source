#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flagB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flagB=0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}

	
	
	return 0;
}
