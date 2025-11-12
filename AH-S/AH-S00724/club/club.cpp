#include<bits/stdc++.h>
using namespace std;
int t,n,p,sum;
int a[100010][5],b[100010];
int dp[100010][5];
int cnt[100010][5][3];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			cout<<max(a,max(b,c))+max(d,max(e,f));
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[++p]=a[i][1];
			if(a[i][2]==0&&a[i][3]==0) sum++;
		}
		if(sum==n){
			sort(b+1,b+1+p,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			cout<<ans<<"\n";
			memset(b,0,sizeof(b));
		}
		else {
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					int t=cnt[i-1][j][k];
					if(dp[i-1][k]+a[i][j]>dp[i][j]&&t<n/2){
						dp[i][j]=dp[i-1][k]+a[i][j];
						cnt[i][j][1]=cnt[i-1][k][1],cnt[i][j][2]=cnt[i-1][k][2],cnt[i][j][3]=cnt[i-1][k][3];
						cnt[i][j][k]++;
					}
				}
			}
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
		}
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
