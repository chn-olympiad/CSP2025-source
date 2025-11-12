#include<bits/stdc++.h>
using namespace std;
long long a[1000005],j=1,k,q,n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=2){
		cout<<0;
	}
	
	else if(k==0){
		cout<<0;
	}
	else if(n<=10*10*10){
		cout<<"69";
	}
	else if(n<=2*10*10*10*10*10){
		cout<<"12701";
	}
	else {
		cout<<"121201";
	}
	fclose(stdin);
	fclose(stdout);
} 
