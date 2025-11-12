#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    int t;
    long long n,a1,a2,a3;
    int ans;
    int j1=0,j2=0,j3=0,q1=0,q2=0,q3=0;
    cin>>t;
    
    for(int j=1;j<=t;j++){
		cin>>n;
		if(q1==n/2){
			a1=a1+a2+a3;
		}
		else if(q2==n/2){
			a2=a1+a2+a3;
		}
		else if(q3==n/2){
			a3=a1+a2+a3;
		}
        else{
			for(int i=0;i<=n;i++){
             cin>>a1>>a2>>a3;
             if(a1>=a2){
		         if(a1>=a3){
			         j1=j1+a1;
			         q1=q1+1;
			     }
		         else{
                     j3=j3+a3;
                     q3=q3+1;
			     }
		     }
		
	        else{
		         if(a1>=a3){
			        j2=j2+a2;
			        q2=q2+1;
		         }
	             else{
			        if(a2>=a3){
				        j2=j2+a2;
				        q2=q2+1;
			        }         
			        else{
				        j3=j3+a3;
				        q3=q3+1;
			        } 
		        }  
	       }
       }
     }
    ans=j1+j2+j3;
    cout<<ans<<endl;
	}
  return 0;
 }
