#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,x,y,z,ans;
int a[1000][3]; 
signed main(){   
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);    
	cin>>t;
	cin>>n;
	for(int i=1;i<=t;++i){
	for(int j=1;j<=n;++j){
		   cin>>a[j][1]>>a[j][2]>>a[j][3];  
		   ans=a[j][1]+ans;
		   }	
		    cout<<ans<<endl;
		           		
   }
   return 0;
}
 
