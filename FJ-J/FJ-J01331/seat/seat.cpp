#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0,c=0,c1=0,q=1,a[1000];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	c=a[0];
	for(int i=1;i<n*m;i++){
		if(a[i]>a[i-1]){
			s=a[i];
			a[i]=a[i-1];
			a[i-1]=s;
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==c){
			c1=i+1;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
		   q=1;
		   for(int z=n;z>=1;z--){
		       if(c1==i+q&&a[i*z-2]==c){
		       	  cout<<i<<" "<<z;
		       	  return 0;
			   }	
		 q++;
		}
	}else{
	 for(int j=1;j<=n;j++){
		if(c1==(i-1)*n+j&&a[(i-1)*n+j-1]==c){
		   cout<<i<<" "<<j;
		   return 0;
		   }	
	    }	
	}
}
	return 0;
}