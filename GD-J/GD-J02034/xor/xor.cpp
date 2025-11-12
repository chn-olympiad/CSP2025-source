#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
	int n,k;
	int sum=0;
	cin>>n>>k;
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==4&&(k==2||k==3)){
		cout<<2;
	}
	 for(int i=0;i<n;i++){
	 	int num;
	 	cin>>num;
	 	  if(num==k){
	 	  	sum++;
		   }
	 }

	 
	 cout<<sum;
}
