#include <bits/stdc++.h>
using namespace std;
int n,a[505];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int kl=a[1]+a[2]+a[3];
		int kl1=max(a[3],max(a[1],a[2]));
		if(kl>kl1*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(n==2){
		cout<<0;
		return 0;
	}
	else if(n==1){
		cout<<0;
		return 0;
	}
	return 0;
}
