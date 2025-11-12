#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int inf=0x3f3f3f3f;
int t,n;
long long a[N][4];
int dp[N][4];
int pos[4],cnt[4];
int close[4];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof dp);
		memset(pos,0,sizeof pos);
		memset(cnt,0,sizeof cnt);
		close[1]=close[2]=close[3]=inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(cnt[j]+1>(n/2)){
					dp[i][j]=ans-close[j]+a[i][j];
				}
				else dp[i][j]=ans+a[i][j];
			}
			ans=max(max(dp[i][1],dp[i][2]),dp[i][3]);
			if(ans==dp[i][1]){
				cnt[1]++;
				pos[1]=i;
				close[1]=min(close[1],min(abs(a[i][1]-a[i][2]),abs(a[i][1]-a[i][3])));
			}
			else if(ans==dp[i][2]){
				cnt[2]++;
				pos[2]=i;
				close[2]=min(close[2],min(abs(a[i][2]-a[i][1]),abs(a[i][2]-a[i][3])));
			}
			else{
				cnt[i]++;
				pos[3]=i;
				close[3]=min(close[3],min(abs(a[i][1]-a[i][3]),abs(a[i][2]-a[i][3])));
			}
		}
		cout<<ans<<endl; 
		ans=0;
	}
	return 0;
} 
