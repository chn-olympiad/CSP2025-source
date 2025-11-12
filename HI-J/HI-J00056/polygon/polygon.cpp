#include "bits/stdc++.h"
using namespace std;
int a[100010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,t=0,r=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		for(i=1;i<=n;i++){
			if(a[i]>t)t=a[i];
			r+=a[i];
		}
		if(r>t*2)cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
} 
