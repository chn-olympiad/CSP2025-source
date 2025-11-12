#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000001],k=1,x;
int main(){
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			k++;
		}	
	}
	if(k%m==0){
		cout<<k/m<<" "<<n;
	}else{
			cout<<k/m+1<<" ";
	if((k/m+1)%2==0){
		k%=m;
		cout<<n-k+1;
	}else{
		k%=m;
		cout<<k;
	}
	k%=m;
	}
	return 0;
} 
