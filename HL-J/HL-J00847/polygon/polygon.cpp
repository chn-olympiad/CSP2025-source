#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int main(){
	feopen("polygon.in","r",stdin);
	feopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>a[i];	
	}
	int cort=0;
	for(int i=1;i<=n-2;i++){
	   for(int j=i;j<=n-2;j++){
	   	  for(int u=j+1;u<=n-2;u++){
	   	  	 for(int y=u+1;y<=n-1;y++){
	   	  	 	int yu=0;
	   	  	 	yu=max(a[j],a[u]);
	   	  	 	yu=max(a[u],a[y]);
	   	  	 	if(a[j]+a[u]+a[y]-yu>=yu){
	   	  	 	  cort+=1;	
				}
			 }
		  }
	   }
	}
	cout<<cort;
	
	return 0;
}
