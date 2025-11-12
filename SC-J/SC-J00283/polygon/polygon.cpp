#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	int n,a[5001],tot=0,da=0,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot+=a[i];
		if(a[i]>da){
			da=a[i];
		}
	}
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		if(da*2<tot){
			cout<<1;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			l+=n-2;
		}
		cout<<l; 
	}
	return 0;
}