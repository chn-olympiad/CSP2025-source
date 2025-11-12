#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	ll ans=1;
	ll b=n;
	for(ll i=n;i>=1;i--){
		ll j=i;
		j=j%998244353;
		ans=(j%998244353)*(ans%998244353);
		ans%=998244353;
	}
	//cout<<0x7fffffffffffffff<<"qw";
	cout<<ans;
	return 0;
}//998244353
//9223372036854775807
/*
ee 			 eeeeeeeeeeeeeeee   ee   ee         ee
  ee         ee 		   ee   ee   ee			  ee
    ee		 ee 		   ee   ee   ee			    ee
             ee 		   ee   ee   ee
ee 			 ee 		   ee   ee   ee
  ee 		 ee 	ee	   ee   ee   ee
    ee 		 ee 	ee	   ee   ee   ee
     		 ee 	ee	   ee   ee   ee
     		 ee 	ee	   ee   ee   ee
        ee		   eeee  		ee   ee
      ee		 ee	   ee            ee
    ee	       ee		 ee      ee  ee
  ee	     ee            ee      eeee
ee	       ee*/
