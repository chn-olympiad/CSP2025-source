#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
  //	freopen("number.out","w",stdout);
   int n,m,a[100][100],s=0,s1=0,s2=0,s3=0;
   cin>>n>>m;
   for(int j=0;j<n;j++){
   	for(int i=0;i<m;i++){
   		cin>>a[i][j];
	   }
   }
   int c=a[0][0];
   for(int j=0;j<n;j++){
   	for(int i=0;i<m;i++){
   		if(a[i][j]>a[0][0]){
   			s2++;
   			c=a[i][j]; 
		   }
	   }
   }
   for(int j=0;j<n;j++){
   	for(int i=0;i<m;i++){
   	i--;
   	s++;
   	s3++;
   	if(s>2){
   		i++;
   		s=s-n;
   		s1++;
	   }
	   if(s1%2!=0){
	   	j=j+1-n;
	   } 
	   if(s3==s2+1){
	   	cout<<i+1<<" "<<j+1;
	   	break;
	   }
	   
	   }
	   
   }
	 
	
	return 0;
} 
