#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	int t;
	int q[5];
	int cntq=0;
	int cntw=0;
	int cnte=0;
	int cnt=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
	    for(int j=0;j<n;j++){
	    	for(int k=0;k<3;k++){
	    		cin>>q[k];	
		    }
		}// ‰»Î   
		for(int j=0;j<n;j++){
    	    for(int k=0;k<3;k++){
    	    	if(k==0){
				    if(q[k]>q[k+1]&&q[k]>q[k+2]){
				    	if(cntq<=n/2){
				    		cnt+=q[k];
				    	    cntq++;	
						}
					}else if(k==1){
						if(q[k]>q[k+1]&&q[k]>q[k-1]){
							if(cntw<=n/2){
								cnt+=q[k];
					            cntw++;
							}
						}
					}else if(k==2){
						if(q[k]>q[k-2]&&q[k]>q[k-1]){
							if(cnte<=n/2){
								cnt+=q[k];
					            cnte++;
							}
					        
						}
					}
					if(k==0){
					    if(q[k]>q[k+1]&&q[k]>q[k+2]){
					    	if(cntq<=n/2){
								cnt+=q[k];
					        	cntq++;	
							}
					    
						}
					}else if(k==1){
						if(q[k]>q[k+1]&&q[k]>q[k-1]){
							if(cntw<=n/2){
								cnt+=q[k];
					            cntw++;
							}
						}
					}else if(k==2){
						if(q[k]>q[k-2]&&q[k]>q[k-1]){
							if(cnte<=n/2){
							    cnt+=q[k];
					            cnte++;	
							}
					       
						}
					}
					if(k==0){
					    if(q[k]>q[k+1]&&q[k]>q[k+2]){
					    	if(cntq<=n/2){
								cnt+=q[k];
								cntq++;
							}
					    
						}
					}else if(k==1){
						if(q[k]>q[k+1]&&q[k]>q[k-1]){
							if(cntw<=n/2){
								cnt+=q[k];
					            cntw++;
							}
					        
						}
					}else if(k==2){
						if(q[k]>q[k-2]&&q[k]>q[k-1]){
							if(cnte<=n/2){
							    cnt+=q[k];
					            cnte++;	
							}
					       
						}
					}
				}
			}
    	}
    	cout<<cnt<<endl;
    	cnt*=0;
    }
   	return 0;
}
