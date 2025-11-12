#include <bits/stdc++.h>
using namespace std;
int main(){



freopen("polyon","i",stdin);
freopen("polgon","w",stdout);




int m,n,a[1000],r,b=0,c=0,c1;
cin>>m>>n;
for(int i=1;i<=n*m;i++){
        cin>>a[i];
}
r=a[1];

for(int i=0;i<n*m;i++){
for(int i=0;i<n*m;i++){

      
        
        if(a[i]<a[i+1]){
        b=a[i];
        a[i]=a[i+1];
        a[i+1]=b;
    
        }}
}for(int i=1;i<n*m;i++){
	if(a[n*m]==r){
		cout<<m<<" "<<n;}
	
else if(a[1]==r){
		cout<<"1"<<" "<<"1";
		break;}
	
	
 else if(a[i]==r){
	
	 c=i/n;
	 c1=i%n;
	 if(c==0){
	 cout<<c+1<<" "<<c*n+c1+1;}
	 else{
		 cout<<c+1<<" "<<c*n+c1; 
		 }
	 }    
}

return 0;}
