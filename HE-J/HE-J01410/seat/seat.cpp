#include <bits/stdc++.h>
using namespace std;

int main(){
  
      long long m,n,p,r,s=1;
      int a[10000010];
      cin>>n>>m;
      cin>>r;
      for(int i=1;i<m*n;i++){
	       cin>>a[i];
	       p=r;
	       if(a[i]>p){
		   s=s+1;
		   m=a[i];
		   }
	  }for(int i=1;i<=n*m;i++){
	  if(s>(i-1)*n&&s<=i*n&&i%2!=0){
		  	cout<<s%n<<i;
		  	return 0;
		  }if(s>(i-1)*n&&s<=i*n&&i%2==0){
		  if(s%n==1){
		  	cout<<n<<i;
		  	long long x;
		  	if(s%n-1=x){
		  		cout<<n-x<<i;
		  		return 0;
			  }
		  }
		  }
	  }return 0; 
  }

