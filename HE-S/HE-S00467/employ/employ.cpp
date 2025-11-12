#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[100001],sum=0;
	string s;
	cin>>n>>m;
  	cin>>s;
  	for(int i=0;i<n;i++){
  		cin>>a[i];
	  }	
	  while(sum<m){
	   	for(int i=0;i<n;i++){
	   		a[0]=a[n-1];
  			if(a[i]>i){
  			 sum++;
  			 
		  }
	  }
}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
