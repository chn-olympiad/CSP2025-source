#include<bits/stdc++.h>
int a[100005][3],dp[100005],n,t,sums[3];
int dfs(int i,int sum){
	if(i==n) return sum;
	int ret=0;
	if(sums[0]<n/2) sums[0]++,ret=std::max(ret,dfs(i+1,sum+a[i][0])),sums[0]--;
	if(sums[1]<n/2) sums[1]++,ret=std::max(ret,dfs(i+1,sum+a[i][1])),sums[1]--;
	if(sums[2]<n/2) sums[2]++,ret=std::max(ret,dfs(i+1,sum+a[i][2])),sums[2]--;
	return ret;
}
bool cmp1(std::pair<int,int> _1,std::pair<int,int> _2){
	return a[_1.second][1]-a[_1.second][0]<a[_2.second][1]-a[_2.second][0];
}
bool cmp2(std::pair<int,int> _1,std::pair<int,int> _2){
	return a[_1.second][0]-a[_1.second][1]<a[_2.second][0]-a[_2.second][1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL),std::cout.tie(NULL);
	std::cin>>t;
	while(t--){
		std::cin>>n;
		std::vector<std::pair<int,int> > st1,st2;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				std::cin>>a[i][j];
			}
			if(a[i][0]>a[i][1]) st1.push_back({a[i][0],i});
			else st2.push_back({a[i][0],i});
		}
		if(n<=13){
			st1.clear(),st2.clear();
			std::cout<<dfs(0,0)<<'\n';
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			if(a[i][0]>a[i][1]&&a[i][1]>a[i][2]){
				if(sums[0]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][0],sums[0]++;
				else if(sums[1]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][1],sums[1]++;
				else dp[i]=dp[i-1]+a[i][2],sums[2]++;
			}else if(a[i][0]>a[i][2]&&a[i][2]>a[i][1]){
				if(sums[0]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][0],sums[0]++;
				else if(sums[2]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][2],sums[2]++;
				else dp[i]=dp[i-1]+a[i][1],sums[1]++;
			}else if(a[i][1]>a[i][2]&&a[i][2]>a[i][0]){
				if(sums[1]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][1],sums[1]++;
				else if(sums[2]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][2],sums[2]++;
				else dp[i]=dp[i-1]+a[i][0],sums[0]++;
			}else if(a[i][1]>a[i][2]&&a[i][0]>a[i][2]){
				if(sums[1]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][1],sums[1]++;
				else if(sums[0]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][0],sums[0]++;
				else dp[i]=dp[i-1]+a[i][2],sums[2]++;
			}else if(a[i][2]>a[i][1]&&a[i][1]>a[i][0]){
				if(sums[2]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][2],sums[2]++;
				else if(sums[1]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][1],sums[1]++;
				else dp[i]=dp[i-1]+a[i][0],sums[0]++;
			}else if(a[i][2]>a[i][0]&&a[i][0]>a[i][1]){
				if(sums[2]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][2],sums[2]++;
				else if(sums[0]<=std::max(i,2)/2) dp[i]=dp[i-1]+a[i][0],sums[0]++;
				else dp[i]=dp[i-1]+a[i][1],sums[1]++;
			}
		}
		sums[0]=sums[1]=sums[2]=0;
		std::cout<<dp[n-1]<<'\n';
	}
}

