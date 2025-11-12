#include<bits/stdc++.h>
using namespace std; 
int t,a[5001][5001],d[100],z[100],c=0;
float n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		for(int z=1;z<=3;z++){
    				cin>>a[i][z];
			}	
		}
      	
      	int w=1;
      	for(int m=1;m<=3;m++){
		  	for(int r=1;r<=n;r++){
      	if(a[r][m]<a[r+1][m]){
      		a[r][m]=a[r+1][m];
      	   a[r][m+1]=0;
	    	a[r][m+2]=0;
		  }	
      	if(a[r+2][m]>a[r][m]){
      		swap(a[r+2][m],a[r][m]);
      		a[r+2][m+1]=0;
	    	a[r+2][m+2]=0;
		  }
		  }
	    for(int j=1;j<=n*0.5;j++){
	    	z[m]+=a[j][m];
	    	
		}
		  }
      
      
	}
	for(int l=1;l<=3;l++){
		c+=z[l];
		
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
