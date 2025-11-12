#include<bits/stdc++.h>
using namespace std;
struct node{
	long long id,sc[5];
}a[101010];
long long n,t;
long long dp[100000][5];
long long maxx,mxid;
long long ans;
int vis[10];
long long s3max;
long long s2max;
bool cmp(node x,node y){
	return x.sc[1]>y.sc[1];
}
void dfs(int k,long long sum){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]>=n/2)continue;
		++vis[i];
		dfs(k+1,sum+a[k].sc[i]);
		--vis[i];
	}
	return;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		ans=0;
		s3max=0;
		s2max=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].sc[j];			
			}
			a[i].id=i;
			s2max=max(s2max,a[i].sc[2]);
			s3max=max(s3max,a[i].sc[3]);
		}
		if(s2max==0&&s3max==0){
	//		cout<<"yes";
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				s2max+=a[i].sc[1];
			}
			cout<<s2max<<'\n';
			continue;
		}
		if(n<=15){
			dfs(1,0);
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int maxx=-111;
			int mxid=0;
			for(int k=1;k<=3;k++){
				mxid=i;
				maxx=a[i].sc[k];
//				if(a[i].sc[k]>=maxx){
//					mxid=k;
//					maxx=a[i].sc[k];
//				}
				for(int j=n/2;j>=1;j--){
					dp[j][mxid]=max(dp[j][mxid],dp[j-1][mxid]+maxx);
				}
			}
	
		}
		cout<<dp[n/2][1]+dp[n/2][2]+dp[n/2][3]<<'\n';
	}
	return 0;
} 

