#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[1000]={0},b[1000]={0},c,k=0,p=0,g[1000]={0};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int l[n][m];
	c=a[0];
	for(int i=-1;i<n*m;i++){	
		if(a[i]<a[i+1]){
		 swap(a[i],a[i+1]);
		 g[i]=a[i];
		}
	}
	for(int i=m*n;i>-2;i--){
		b[i]=g[i];
	}
	for(int i=-1;i<n;i++){
		if(p%2==0){
	      for(int j=-1;j<m;j++){
	   	    l[i][j]=b[j];
	   	    if(l[i][j]==c){
	   	  	  cout<<l[i][j];
	   	  	  return 0;
		    }
		  }
		  }else{
			for(int j=m;j>-1;j--){
	   	      l[i][j]=b[j];
	   	      if(l[i][j]==c){
	   	  	    cout<<l[i][j];
	   	  	    return 0;
		      }
		    }
		  }
			 p++;
	   }	
	return 0;
}
