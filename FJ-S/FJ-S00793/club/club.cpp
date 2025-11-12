#include<bits/stdc++.h>
using namespace std;
int dpsg[505][505][505],ans=0,n,t,a[10000][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int rr=1;rr<=t;rr++){
		cin>>n;
	for(int o=1;o<=n;o++){
		cin>>a[o][1]>>a[o][2]>>a[o][3];
	}
	if(n<=500){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int u=0;u<=n/2&&u<=i;u++){
				for(int o=0;o<=n/2&&o<=i;o++){
					if(i-u-o>n/2) continue;
					
					else dpsg[i][u][o]=max(dpsg[i-1][u-1][o]+a[i][1],max(dpsg[i-1][u][o-1]+a[i][2],dpsg[i-1][u][o]+a[i][3]));
					
				}
			}
		}
		for(int u=0;u<=n/2;u++){
				for(int o=0;o<=n/2;o++){
					if(n-u-o>n/2) continue;
					ans=max(ans,dpsg[n][u][o]);
				
			}
		}
		cout<<ans<<endl;
	}
}
}
