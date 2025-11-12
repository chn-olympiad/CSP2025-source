#include<bits/stdc++.h>
using namespace std;
int a[50000];
int n;
int lun=0;
void dfs(int n1,int m,int max1){
	if(n1>=n){
		return ;
	}
	if(n1>=3&&m>2*max1){
			lun++;
	}	
	for(int i=n1+1;i<=n;i++){
		dfs(n1+1,m+a[i],max(max1,a[i]));
			
	}
	return ;
}
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
   }
   if(n<3){
	   cout<<0;
   }
   else{
	  dfs(1,0,0);
	  cout<<lun;
   }
   return 0;
}
