#include<bits/stdc++.h>
using namespace std;
int t,n,dp[507][507][507],ans,o;
struct node{
	int x,y,z,yz,xy;
}a[100007];
bool cmp(node s1,node s2){
	return s1.xy>s2.xy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		o=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z; 
			a[i].yz=a[i].y-a[i].z;
			a[i].xy=a[i].x-a[i].y;
			if(a[i].z!=0)o=1;
		}
		memset(dp,0,sizeof(dp));
		if(!o){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans+=a[i].x;
				else ans+=a[i].y;
			}
			cout<<ans<<endl;
		}
		else{
//			for(int i=1;i<=n;i++){
//				cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
//			}
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int o=0;o<=n;o++){
						dp[i][j][o]=0;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(n/2,i);j++){
					for(int o=0;o<=min(n/2,i-j);o++){
						if(j>0)dp[i][j][o]=max(dp[i][j][o],dp[i-1][j-1][o]+a[i].x);
						if(o>0)dp[i][j][o]=max(dp[i][j][o],dp[i-1][j-1][o-1]+a[i].y);
						if(i-j-o>0)dp[i][j][o]=max(dp[i][j][o],dp[i-1][j][o]+a[i].z);
					}
				}
			}
			for(int j=0;j<=n/2;j++){
				for(int o=0;o<=n/2;o++){
					ans=max(ans,dp[n][j][o]);
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//3
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
