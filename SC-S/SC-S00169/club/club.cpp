#include<bits/stdc++.h>
using namespace std;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n;
int main(){
int sum=0,maxn=0,maxn1=0,a[n][n],s[3];
	cin>>t;
	while(t>0){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
  }
  for(int i=1;i<=n;i++){
  	for(int j=1;j<=3;j++){
  		 if(a[i][j]>maxn){
  		 	maxn=a[i][j];
		   }if(a[i][j]>maxn){
  		 	maxn=maxn1;
  		 	a[i][j]=maxn;
		   }
		   s[j]++;
		   if(s[j]>n/2){
		   	maxn=maxn1;
		   }
	  }
	  
	  sum+=maxn;
	  maxn=0; 
  }
  cout<<sum;
  sum=0;
}
	return 0;
}