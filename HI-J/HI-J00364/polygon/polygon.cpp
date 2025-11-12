#include <bits/stdc++.h>
using namespace std;
int n,num[5001],sum[5001],lemp1,lemp2;
int main(){
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>num[i];
	 }
	 for(int x=1;x<=n;x++){
	 	lemp1=0,lemp2=0;
	 	for(int y=x;y<=n;y++){
	 			lemp1=num[y]+lemp1;
	 			lemp2=(max(num[y-1],num[y]),lemp2);
			 }
			 if(lemp1=lemp2*2)sum=sum+1;
		 }
		 cout<<sum;
return 0;
}
