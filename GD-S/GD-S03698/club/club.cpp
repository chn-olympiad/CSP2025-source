#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][3],dp[205][205][205];
int cnt[3],s[3],ans;
vector<int>b,c[2],d;
int Max(int a,int b,int c){
	int ma=a,p=0;
	if(b>ma) ma=b,p=1;
	if(c>ma) ma=c,p=2;
	return p;
}
void solve(){
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i&&j<=n/2;j++)
			for(int k=0;j+k<=i&&k<=n/2;k++){
				if(i-j-k>n/2) continue;
				if(j) dp[i][j][k]=dp[i-1][j-1][k]+a[i][0];
				if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][1]);
				if(j+k!=i) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
			}
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			if(i+j>=n/2)
				ans=max(ans,dp[n][i][j]);
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=0;
		bool f1=false,f2=false;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
				if(j&&a[i][j]) f1=true;
				if(j==2&&a[i][j]) f2=true;
			}
		if(n<=200) solve();
		else if(!f1&&!f2){
			b.clear();
			for(int i=1;i<=n;i++)
				b.push_back(a[i][0]);
			sort(b.begin(),b.end());
			for(int i=0;i<n/2;i++)
				ans+=b[b.size()-1-i];
			printf("%d\n",ans);
		}else if(!f2){
			for(int i=1;i<=n;i++){
				if(a[i][0]>a[i][1]){
					ans+=a[i][0];
					c[0].push_back(i);
				}else{
					ans+=a[i][1];
					c[1].push_back(i);
				}
			}
			if(c[0].size()==c[1].size()) printf("%d\n",ans);
			else if(c[0].size()>c[1].size()){
				for(auto i:c[0])
					d.push_back(a[i][0]-a[i][1]);
				sort(d.begin(),d.end());
				for(int i=0;i<c[0].size()-n/2;i++)
					ans-=d[i];
				printf("%d\n",ans);
			}else{
				for(auto i:c[1])
					d.push_back(a[i][0]-a[i][1]);
				sort(d.begin(),d.end());
				for(int i=0;i<c[0].size()-n/2;i++)
					ans-=d[i];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
