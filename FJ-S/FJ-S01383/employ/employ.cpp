#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],ans=0;
string s;
      int main(){
      	freopen("employ.in","r",stdin);
      	freopen("employ.out","w",stdout);
      	cin>>n>>m;
      	cin>>s;
      	for(int i=1;i<=n;i++)cin>>a[i];
      	for(int i=m;i<=n;i++){
      		long long x=1;
      		for(int j=2;j<=i;j++){
      			x=x*j%998244353;
			  }
			  ans=(ans+x)%998244353;
		  }
		  cout<<ans;
      	return 0;
	  } 
