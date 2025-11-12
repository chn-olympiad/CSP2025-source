#include<bits/stdc++.h>
using namespace std; 
int a1,a2,a3;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0; 
	}
	else if(n==3){
		cin>>a1>>a2>>a3;
		if(2*max(a1,max(a2,a3))<=a1+a2+a3){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
		return 0; 
	}
	cout<<0;
	
}
