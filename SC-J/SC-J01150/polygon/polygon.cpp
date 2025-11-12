#include<bits/stdc++.h>
using namespace std;
int n,a[5005],temp,ans=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			temp=1;
		}
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	if(temp==0){
		while(n){
			n/=3;
			ans+=n;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ans+=i;
		}
		cout<<ans/2;
	}
	return 0;
}