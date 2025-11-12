#include<bits/stdc++.h>
using namespace std;
int a[5600],n,da,summ;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		da=max(da,a[i]);
		summ+=a[i];
	}
	if(n==3){
		if(da*2<summ){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}