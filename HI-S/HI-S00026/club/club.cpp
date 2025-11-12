#include<bits/stdc++.h>
using namespace std;
int a,n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int q=0;q<t;q++){
    	int sum=0;
    	cin>>n;
    	int a[10000][4];
    	for(int i=0;i<n;i++){	
    	    for(int j=0;j<3;j++){
    		cin>>a[i][j];
    	}
    	int max=a[i][0];
    	int j[4];
    	for(int y=0;y<=3;y++){
    		if(a[i][y]>max){
    			if(j[y]!=n/2){
				max=a[i][y];
				j[y]++;
				}
				else{
					int mbx=a[i][0];
    	            int j[4];
    	            for(int w=0;w<=3;w++){
    		            if(a[i][w]>mbx){
    			        if(j[w]<n/2){
				        max=a[i][w];
				        max=mbx;
				        j[w]++;
				    }
				else{    	
				int mcx=a[i][0];
    	        int j[4];
    	for(int e=0;e<=3;e++){
    		if(a[i][e]>mcx){
    			if(j[e]<n/2){
				mcx=a[i][e];
				max=mcx;
				j[e]++;
				}
			}
		}
					
				}
			}
		}
				}
			}
		}
		sum=sum+max;
		}
		cout<<sum<<endl;
	
	
	}
    
    
    
    
	return 0;
} 
