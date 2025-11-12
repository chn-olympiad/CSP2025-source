#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,y=1,a[500005],sum[500005],dp[500005],ans,dis[500005];
vector<int>m[500005],help_m[2000005];
struct s{
	int v,w;
};
bool operator < (s a,s b){
	return a.w<b.w;
}
priority_queue<s>q;
void solve_in_n2(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if((sum[i]^sum[j])==k) m[i].push_back(j+1);
		}
	}
	for(int i=1;i<=n;i++){
		if(m[i].empty()) continue;
		for(int j=0;j<m[i].size();j++){
			for(int k=(j==0 ? 1 :m[i][j-1]);k<=m[i][j];k++) dp[i]=max(dp[i],dp[k-1]+1);
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return;
}
void solve_in_n(){
	for(int i=0;i<=n;i++){
		help_m[sum[0]^sum[i]].push_back(i);
	}
	for(int i=0;i<=n;i++){
		for(int j:help_m[k^sum[0]^sum[i]]){
			if(i<j){
				m[i+1].push_back(j+1);
			}
		}
	}
	q.push({1,0});
	while(!q.empty()){
		s net=q.top();
		q.pop();
		for(int i:m[net.v]){
			if(i==net.v) continue;
			dis[i]=net.w+1;
			q.push({i,dis[i]});
		}
	}
	for(int i=1;i<=n+1;i++) ans=max(ans,dis[i]);
	cout<<ans;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]>1) y=0;
	}
	if(n<=5000) solve_in_n2();
	else solve_in_n();
	return 0;
}
