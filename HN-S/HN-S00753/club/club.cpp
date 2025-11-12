#include<bits/stdc++.h>
#define int long long 
int n,m,ma;
    
  
using namespace std;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m;
	int l[m];
    for(int q=0;q<n;q++){
    	int a[n][3], b[n/2][3];
    	for(int i=0;i<n;i++){
				for(int j=0;j<3;j++){
		cin>>a[i][j];	
			}

			
			}
		if(n==2){
			int max=0,x,y;
		for(int i=0;i<n;i++){
				for(int j=0;j<3;j++){
	             int c=max;
	             max=ma(max,a[i][);
	             if(c!=max){
	             	x=i;
				 }
	}
		}	
			if(n==2){
			int max=0,x,y;
		for(int i=0;i<n;i++){
				for(int j=0;j<3;j++){
	             int c=max;
	             max=ma(max,a[i][j]);
	             if(c!=max){
	             	x=i;
				 }
	}
		}	
		}	
		}	
}

	return 0;
} 
