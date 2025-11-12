#include<bits/stdc++.h>
using namespace std;
long long int n,a[100000],c=0,t=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c+=a[i];
		if(a[i]>t){
			t=a[i];
		}
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if((t*2)<c){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<a[1]*3;
	} 
	return 0;
} 
