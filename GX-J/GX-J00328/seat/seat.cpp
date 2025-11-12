#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
    
       int n,m;
       cin>>n>>m;
       int a[n*m];
       int b[n][m];
       for(int i=0;i<n*m;i++){
		   cin>>a[i];
		   }  
		int xiaoR= a[0];
		sort(a,a+n*n);
		
		int k=0,l=0;
		if(m%2==0){
		for(int j=0;j<m/2;j++){
	       	for(int i=0;i<n;i++){
		       b[i][j+l]=a[n*m-i-1-k];
			}
			k+=n;
			for(int i=0;i<n;i++){
				b[n-i-1][j+1+l]=a[n*m-1-i-k];
				}
			k+=n;
			l+=1;
		}
	}
	
	
	
	
	
	
		else if(m%2==1){
			for(int j=0;j<(m-1)/2;j++){
	       	for(int i=0;i<n;i++){
		       b[i][j+l]=a[n*m-i-1-k];

			}
			k+=n;
			for(int i=0;i<n;i++){
				b[n-i-1][j+1+l]=a[n*m-1-i-k];
				}
			k+=n;
			l+=1;
		}
	
	
	
		for(int i=0;i<n;i++){
		    b[n-i-1][m-1]=a[n-1];
		}
	}
		
		
	
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(b[i][j]==xiaoR){
					cout<<j+1<<' '<<i+1;
					}
				}
			}
	
   
 fclose(stdin);
 fclose(stdout);

    return 0;
}
