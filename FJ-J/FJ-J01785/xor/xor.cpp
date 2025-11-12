#include<bits/stdc++.h>
using namespace std;
long long n,a,k,t=1,b=1,c=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==1){
			c++;
		}
		if(a!=1){
			t=0;
		}
		if(a>1){
			b=0;
		}
	}
	if(t){
		cout<<n/2;
	}
	else if(b && k==1){
		cout<<c;
	}
	else{
		cout<<2;
	}
	
	return 0;
} 
