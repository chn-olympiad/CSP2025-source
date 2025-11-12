#include<bits/stdc++.h>
using namespace std;
long long t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,ans=0,sx=0,sy=0,sx=0,dp[100010][3];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx=max(max(a[i].x,a[i].y),max(a[i].y,a[i].z));
			ans+=a[i].mx;
			if(a[i].mx=a[i].x){
				ans+=a[i].mx;
				sx++; 
			}
			if(a[i].mx=a[i].y){
				ans+=a[i].mx;
				sy++; 
			}
			if(a[i].mx=a[i].z){
				ans+=a[i].mz;
				sz++; 
			}
		}
		if(sx<=n/2&&sy<=n/2&&sz<=n/2){
				cout<<ans<<endl;
		}
		else if(sx>n/2){
			while(sx>n/2){
				
			}
		}
	}
	return 0;
}
