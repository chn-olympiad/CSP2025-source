//第一眼看上去像是贪心，每个部门都拿最大的
//但是贪心又好像不兑，应该是线性递推
//如果这样做的话我们还需要去记录容量
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+500;
int dp[250][250][250];//第一维表示当前递推到哪里,第二维代表容量，第三维代表选啥
int a[N][3];
int n;
int dfs(int pos,int cnt1,int cnt0,int cnt2){//发现只需要记录最大的容量即可
	if(dp[cnt1][cnt0][cnt2])return dp[cnt1][cnt0][cnt2];
	if(pos==n+1){
		return 0;
	}
	int maxn=0;
	if(cnt1<n/2)maxn=max(maxn,dfs(pos+1,cnt1+1,cnt0,cnt2)+a[pos][1]);
	if(cnt2<n/2)maxn=max(maxn,dfs(pos+1,cnt1,cnt0,cnt2+1)+a[pos][2]);
	if(cnt0<n/2)maxn=max(maxn,dfs(pos+1,cnt1,cnt0+1,cnt2)+a[pos][0]);
	dp[cnt1][cnt0][cnt2]=maxn;
	return maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		//int n;
		cin>>n;
		int flag1=1,flag2=1;
		for(int j=1;j<=n;j++){
			for(int k=0;k<=2;k++){
				cin>>a[j][k];
			}
			if(a[j][1] or a[j][2]){
				flag1=0;
			}
			if(a[j][2])flag2=0;
		}
		if(flag1){//一维的
			vector <int> v;
		    for(int j=1;j<=n;j++)v.push_back(a[j][0]);
		    sort(v.begin(),v.end());
		    int ans=0;
		    for(int j=v.size()-1;j>=n/2;j--)ans+=v[j];
		    cout<<ans<<"\n";
		    continue;
		}
		cout<<dfs(1,0,0,0)<<"\n";
		//int cnt0=0,cnt1=0,cnt2=0;
		//for(int j=1;j<=n;j++){
		//	dp[j][1]=max(dp[j-1][2],max(dp[j-1][0]))+a[j][1];
		//	dp[j][0]=max(dp[j-1][1],dp[j-1][2])+a[j][0];
		//	dp[j][2]=max(dp[j-1][1],dp[j-1][0])+a[j][2];
		//}
		//cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<"\n";
	}
	return 0;
}
