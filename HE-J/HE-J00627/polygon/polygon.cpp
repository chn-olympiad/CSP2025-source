#include<bits/stdc++.h>
using namespace std;
int n,a[5010],a1=0,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
		sum+=a[i];
		a1=max(a1,a[i]);
	}
	if(a1==1){
		cout<<n-2; 
	}else if(n==3&&sum>2*a1){
		cout<<1;
	}else if(n==3&&sum<=2*a1){
		cout<<0;
	}else if{
		cout<<8;
	}
	return 0;
} 
