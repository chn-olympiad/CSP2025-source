#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool t=true,tt=true;
	int tn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			t=false;
			
		} 
		if(a[i]>1){
			tt=false;
		} 
		if(a[i]==1){
			tn++;
		}
	}
	if(t){
		if(k==0){
			cout<<n/2;
		}
		else{
			cout<<n;
		}
	}
	else if(tt){
		if(k==0){
			
		}
		else{
			cout<<tn;
		}
	}
	else{
		
	}
	return 0;
}
