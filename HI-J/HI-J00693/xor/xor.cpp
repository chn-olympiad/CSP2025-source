#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cs=0,cs1=0;
	cin>>n>>k;
	int xg[k]={};
	for(int a=0;a<n;a++){
		cin>>xg[a];
		if(xg[a]!=1){
			cs=1;
		}
		else if(xg[a]==1){
			cs1++;
		}
	}
	if(cs==0){
		if(k==0){
			cout<<n/2;
		}
		else{
			cout<<n;
		}
	}
	else{
		if(k==0){
		   cout<<n-cs1+cs1/2;	
		}	
		else{
		     cout<<(n-cs1)/2+cs1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
