#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	bool vis[10005][3];
	int n,t,a[10005][3],b[10005],c[10005],d[10005],club[3],e[10005][3],maxn[10005],dp[10005],x;
	cin>>t;
	while(t--){
		int ans=0;
		x=n/2;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(club,0,sizeof(club));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==0==a[i][3]) dp[i]=a[i][1];
			if(a[i][1]==0==a[i][2]) dp[i]=a[i][3];
			if(a[i][3]==0==a[i][1]) dp[i]=a[i][2];
		}
		sort(dp,dp+1+n);
				for(int i=x;i<=n;i++) ans+=dp[i]; 
			cout<<ans<<endl;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
