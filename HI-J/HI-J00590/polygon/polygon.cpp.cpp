#include<bits/stdc++.h>
using namespace std;
int a,b;//(a为行，b为列) 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	 cin>>a>>b;
	 int s[10005];
	 for(int i=1;i<=a*b;i++){
	 	cin>>s[i];
	 }
	 int r=s[1];
	 for(int i=a*b-1;i>=1;i--){
	 	for(int j=1;j<=i;j++){
	 		if(s[j]<s[j+1]){
	 			swap(s[j],s[j+1]);
		}
		
			 
		 }
	}
	 //
int x,y;
	 for(int i=1;i<=a*b;i++){
	 	if(s[i]==r){
	 		if(i<=a){
	 			cout<<1<<" "<<i;
	 			break;
			 }
			 else{
			 	for(int t=2;t<=b;t++){
			 		if(i<t*a){
			 			//
			 			if(t%2==0){
			 				int v=t/2*10;
			 				cout<<t<<" "<<i-v;
			 				break;
						 }
						 //奇数
						 ///////////////////
						 int mvp[1005];
						 for(int f=1;f<=2*a-1;f++){
							 for(int k=1;k<=2*a-1;k++){
							 	if(k%2==1){
							 		mvp[f]=k;
								 }
							 	
							 	continue;
							 	
							 }
						}
						 ////////////////
						else if(t%2==1){
							
						}
		 
						 	
						 }
					 }
				 }
			 }
		 }
	 

	

	return 0;
}
