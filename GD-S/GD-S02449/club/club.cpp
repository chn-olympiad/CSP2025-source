#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[100005][5],c[100005],dp[10005][5005][3];
bool flag2,flag3;
void dfs(int x,int suma,int sumb,int sumc,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(suma<n/2) dfs(x+1,suma+1,sumb,sumc,sum+a[x][1]);
	if(sumb<n/2) dfs(x+1,suma,sumb+1,sumc,sum+a[x][2]);
	if(sumc<n/2) dfs(x+1,suma,sumb,sumc+1,sum+a[x][3]);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		bool flag2=true,flag3=true;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2&&a[i][j]) flag2=false;
				if(j==3&&a[i][j]) flag3=false;
				c[i]=a[i][1];
			}
		}
		if(flag2&&flag3){
			sort(c+1,c+n+1);
			for(int i=n;i>=n/2+1;i--) ans+=c[i];
			cout<<ans<<endl;
			continue;
		}
		if(!flag2&&flag3){
			for(int i=1;i<=n;i++){
				for(int j=min(i,n/2);j>=1;j--){
					dp[i][j][1]=dp[i-1][j-1][1]+a[i][1];
					dp[i][j][2]=dp[i-1][j-1][2]+a[i][2];
					dp[i][j][1]=max(dp[i][j][1],dp[i-1][i-j][2]+a[i][1]);
					dp[i][j][2]=max(dp[i][j][2],dp[i-1][i-j][1]+a[i][2]);
					ans=max(ans,max(dp[i][j][1],dp[i][j][2]));
				}
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
