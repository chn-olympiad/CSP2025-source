#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		int m=0,z=0;
		for(int i=0;i<3;i++){
			z+=a[i];
			if(m<=a[i]){
				m=a[i];
			}
		}
		if(z>2*m){
			cout<<1;
		}else{
			cout<<0;
		}
		
	}else{
		cout<<0;
	}
	
	return 0;
}
