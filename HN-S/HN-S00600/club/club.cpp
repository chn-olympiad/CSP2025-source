#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000][1000],m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
        if(n==2){
		   for(int j=1;j<=3;j++){
		    for(int i=1;i<=3;i++){
		    	if(i!=j){
		    		m=max(m,a[1][j]+a[2][i]);
				}
			}
		  }  
		   cout<<m; 
		}
		
    }
	return 0;
}
