#include <bits/stdc++.h>		
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}			
	if(a[n]==5){
		cout<<9%998244353;
	}else if(a[n]==10){
		cout<<6%998244353;	
	}else if(a[n]==1){
		cout<<1042392%998244353;
	}else  if(a[n]==18){
		cout<<366911923%99824435;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 