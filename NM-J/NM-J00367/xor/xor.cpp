#include<bits/stdc++.h>
using namespace std;
int a[50005],n,k,cnt;
int main(){
  cin>>n>>k;
  for(int i=1;i<=n;i++){
	  cin>>a[i];
  }
  for(int i=1;i<=n;i++)if(a[i]>=0&&a[i]<=1){
	  for(int j=1;j<=i;j++)
        for(int h=i;h<=j;h++){
		  if(i==j)if((a[h]^a[h])==k)cnt++;
		  if((a[h]^a[h+1])==k) cnt++;
		  }
		  }
    
	cout<<cnt;	
  return 0;


}
