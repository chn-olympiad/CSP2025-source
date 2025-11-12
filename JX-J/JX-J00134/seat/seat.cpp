#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,x,b[15][15];

int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  int js=n*m+1;
  for(int i=1;i<=(n*m);i++){
	 
	  cin>>a[i];
	   if(i==1){
		  x=a[i];
		  }
	  }
	  sort(a+1,a+1+(n*m));
	  for(int i=1;i<=m;i++){
		  if(i%2==1){
			  for(int j=1;j<=n;j++){
				    js--;
				    b[j][i]=a[js];
		    
				  }
			  
			  }
		
		if(i%2==0){
			  for(int j=n;j>=1;j--){
				  js--;
				    b[j][i]=a[js];
				  }
			  
			  
			  }
		  }
		  for(int i=1;i<=n;i++){
			  for(int j=1;j<=m;j++){
				  if(b[i][j]==x){
					  cout<<j<<" "<<i;
					  return 0;
				  }
				  }
			  }
return 0;
}
