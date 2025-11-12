#include<bits/stdc++.h>
//³ÂË¼Ôó gz s00469 
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int s[100000];
	int n,a1,b1,c1,a2=0,b2=0,c2=0;
	int ab[100000];
	int bc[100000];
	int ac[100000];
	cin>>n;
	int n1;
//	cout<<"testpoint";
	int db=11110;
	int db2;
	int total=0;
	//
	for(int i=1;i<=n;i++){
		cin>>n1;
		total=0;
	//	cout<<" testpoint 2 " ;
//------------------------------
		for(int j=1;j<=n1;j++){
			cin>>a1>>b1>>c1;
			if(a1>=b1&&a1>=c1){
				a2++;
				total+=a1;
				s[j]=1;
				
			}
			
			else if(b1>=c1&&b1>a1){
				b2++;
				total+=b1;
				s[j]=2;
					
			}
			else {
				total+=c1;
				c2++;
				s[j]=3;
				
			}
			ab[j]=a1-b1;
			ac[j]=a1-c1;
			bc[j]=b1-c1;
			
	   	
	}
		while(a2>n1/2||b2>n1/2||c2>n1/2){
			if(a2>n1/2){
			  
			    a2--;
				for(int k=1;k<=n1;k++){
				
					if(s[k]==1&&ab[k]>=0&&ac[k]>=0){
						
					  if(abs(ab[k])<=db){
					  	db=abs(ab[k]);
					  	
					  	db2=k; 
						  
					  }  
					  
					  if(abs(ac[k])<=db){
					  	db=abs(ac[k]);
					  	db2=-k;
					  	
					  }   
					}
				}
	//1 2 10 9 8 4 0 0
				if(db2>0){
					s[db2]=2;
					total-=db;
					db=10000;
					b2++;
				}
				else{
					s[-db2]=3;
					total-=db;
					db=100000;
					c2++;
				}
			}
		//	cout<<"testpoint 8";
				if(b2>n1/2){
			  
			    b2--;
				for(int k=1;k<=n1;k++){
					if(s[k]==2&&ab[k]<=0&&bc[k]>=0){
						
					  if(abs(ab[k])<=db){
					  	db=abs(ab[k]);
					  	
					  	db2=k; 
						  
					  }  
					  
					  if(abs(bc[k])<=db){
					  	db=abs(bc[k]);
					  	db2=-k;
					  	
					  }   
					}
				}
	//1 2 10 9 8 4 0 0
				if(db2>0){
					s[db2]=1;
					total-=db;
					db=10000;
					a2++;
				}
				else{
					s[-db2]=3;
					total-=db;
					db=100000;
					c2++;
				}
			}
		//	cout<<"testpoint 8";
		if(c2>n1/2){
			  
			    a2--;
				for(int k=1;k<=n1;k++){
					if(s[k]==3&&bc[k]<=0&&ac[k]<=0){
					  if(abs(bc[k])<=db){
					  	db=abs(bc[k]);
					  
					  	db2=k; 
				
					  }  
					 
					  if(abs(ac[k])<=db){
					  	db=abs(ac[k]);
					  	db2=-k;
					  	
					  }   
					}
				}
	//1 2 10 9 8 4 0 0
				if(db2>0){
					s[db2]=2;
					total-=db;
					db=10000;
					b2++;
				}
				else{
					s[-db2]=1;
					total-=db;
					db=100000;
					a2++;
				}
			}
		//	cout<<"testpoint 8";
	    }
			
//------------------------------
	cout<<total<<endl;
	}
}
