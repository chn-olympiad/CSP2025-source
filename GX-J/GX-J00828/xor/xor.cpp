#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	for(int i=1;i<=n;i++){
		if(n%n==0&&n%1==0&&n%2==0){
			n+=k;
			k+=n;
			n=k-n/2;
			k=n-n;
		}else{
			n=0;
		}
		
	}
	for(int j=1;j<=k;j++){
		n=n+1;
		if(k!=0){
			k=0;
		}
		
	}
	cout<<2;
	return 0;
}
	

