#include<bits/stdc++.h>
using namespace std;
long long n,k,p=0;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
   cin>>n>>k;
   long long o=0;
	bool fl[500005];
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   	if(a[i]==1){
   		p++;
	}if(a[i]==1&&a[i-1]==1&&fl[i-1]==false){
				fl[i]=true;
			o++;
			}
   }
   if(k==0){
   
   	if(n==p){	
   		cout<<n/2;
	}else{
	
			
		
		
		cout<<n-p+o;
	}
   
   }if(k==1){
   	cout<<p;
   } 
	return 0;
} 
