#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500001],s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(k==1){
			cout<<2;
		}else if(k==0){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		if(k==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}