#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
		   int x=0,ma=-1;
		   for(int k=j;k<j+i;k++){
		       x+=a[k];
		       ma=max(ma,a[k]);
	       }
	       if(x>ma*2){
	       	ans++;ans%=mod;
		   }
	    }
	}
	cout<<ans;
	return 0;
}
