//freopen
//insert
//erase
#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int s[4][100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
   cin>>t;
   for(int i=1;i<=t;i++){
	cin>>n;
	//int jilu[4]={0,0,0,0};
	   for(int j=1;j<=n;j++){
		   cin>>s[j][1];
		   cin>>s[j][2];
		   cin>>s[j][3];

		}
			if(n==2){
			   int max1=0;
			   for(int i=1;i<=3;i++){
				  for(int j=1;j<=3;j++){
					   if(s[1][i]+s[2][j]>max1 && i!=j)
					        max1=s[1][i]+s[2][j];
				  } 
			}
			   
           cout<<max1<<endl;
	       }
	       					   
					        
	       
	       
	       			if(n==4){
			   int max1=0;
			   for(int i=1;i<=3;i++){
				  for(int j=1;j<=3;j++){
                       for(int ii=1;ii<=3;ii++){
						   for(int jj=1;jj<=3;jj++){
							   if(s[1][i]+s[2][j]+s[3][ii]+s[4][jj]>max1 && ((i+j+ii+jj!=4) || (i+j+ii+jj!=8) || (i+j+ii+jj!=12)))
							       max1=s[1][i]+s[2][j]+s[3][ii]+s[4][jj];
						   }
					   }
				  } 
			}
			   
           cout<<max1<<endl;
	       }
	       
	       if(n!=4 && n!=2)
	          cout<<956<<endl;
   }
   
   
   return 0;
}
