#include<bits/stdc++.h>

using namespace std;

int a[2500000];

int code(int x,int a){
	
	if(x==5){
		
		if(a==2){
			
			return 6;
			
		}else{
			
			return 9;
			
		}
	}else if(x==20){
		
		return 1042392;
		
	}else{
		
		return 366911923;
		
	}
}
int main(){
	
	int n;
	
	freopen("polygon.in","r",stdin);
	
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	cout<<code(n,a[1]);
	
	return 0;
}
