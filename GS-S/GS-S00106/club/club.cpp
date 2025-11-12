#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long n,ans=0,sum=0,q=0;
long long t,m,p;
long long a[100005][3],b[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long j=1;j<=3;j++){
		cin>>n;
		for(long long i=1;i<=n;i++){
		    cin>>a[i][1]>>a[i][2]>>a[i][3];
	    }
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=3;j++){
		   	if(n==2){
		        if(a[1][j]>a[1][j-1]){
		        	b[1][m]=a[1][j];
		        	m=j;
				}
			    else{
				    b[1][m]=a[1][j-1];
				    m=j-1;
			    }
		        if(a[2][j]>a[2][j-1]){
		        	b[2][p]=a[2][j];
		        	n=j;
				}
			    else{
				    b[1][p]=a[1][j-1];
				    n=j-1;
			    }
			    if(m==p){
			    	if(b[1][m]>=b[2][p]){
					    if(n==1){
			    		    b[2][p]=max(b[2][2],b[2][3]);
					    }
			    	    else if(p==2){
			    		    b[2][p]=max(b[2][1],b[2][3]);
					    }
					    else{
						    b[2][p]=max(b[2][1],b[2][2]);
					    }
				        ans=b[1][m]+b[2][p];
		                cout<<ans;
		                return 0;
			        }
			        else{
			        	if(n==1){
			    		    b[1][p]=max(b[1][2],b[1][3]);
					    }
			    	    else if(n==2){
			    		    b[1][p]=max(b[1][1],b[1][3]);
					    }
					    else{
						    b[1][p]=max(b[1][1],b[1][2]);
					    }
				        ans=b[1][m]+b[2][p];
		                cout<<ans;
		                return 0;
					}
			   }  
		    }
	    }
    }
	return 0;
}
