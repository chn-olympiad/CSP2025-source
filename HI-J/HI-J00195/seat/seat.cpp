#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.txt","r",stdin);
	freopen("seat.txt","w",stdout);
	int n,m,d=0;
	cin>>n>>m;
	int a[n][m],b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		
	} int c=b[0];
	for(int i=0;i<n*m;i++){
			if(b[i+1]>b[i]){
			swap(b[i],b[i+1]); 
			i=0;}
	}
	
    for(int i=1;i<=m;i++){
    
		
		if(i%2==0){
		for(int j=n;j>=1;j--){
		   
		  
			if(c==b[d]) cout<<i<<" "<<j; d++;
			
		}
		}	else{
		
    		for(int j=1;j<=n;j++){
    		
    		if(c==b[d]) cout<<i<<" "<<j;
    		d++;
			
			}
		}} 
		
    	
	
    
	return 0;
} 
