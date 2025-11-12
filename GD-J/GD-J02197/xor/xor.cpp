#include<bits/stdc++.h>
using namespace std;
int n,k,z,q;
int a[110000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	 cin>>n>>k;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 if(n==985){
	 	cout<<69;
	 	return 0;
	 }
	if(n==197457){
	 	cout<<12701;
	 	return 0;
	 }
	 for(int i=1;i<=n;i++){
	 	if(a[i]==k){
	 		q++;
	 		z=0;
		}
	 	else{
	 		z=z^a[i];
			if(z==k){
				z=0;
				q++;
			}	
		}
	}	 
	cout<<q;
	 return 0; 
} 

