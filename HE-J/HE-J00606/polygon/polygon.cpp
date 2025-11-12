#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
	int n;

	cin>>n;

	if(n==3){
			int a[3]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+3);
	if(a[0]+a[1]>a[2]){cout<<1;
	}
	else{cout<<0;
	}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
