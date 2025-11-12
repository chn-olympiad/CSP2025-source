#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5008]={ },cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<0;	
	}
	else if(n==1){
		cout<<0;	
	}
	else if(n==3 && a[0]+a[2]>a[1] &&a[1]-a[2]<a[0]){
		cout<<1;
	}
	
	return 0;
}
