#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
const int mod=998244353;
int n,k;
int cnt=0;
vector<int> apr[maxn];
int head[maxn];
int nxt[maxn];
int ver[maxn];
int a[maxn];
int sum[maxn];
pair<int,int> dp[maxn];
void add(int u,int v){
	ver[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		apr[sum[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		int x=sum[i]^k;
		for(int j=0;j<apr[x].size();j++){
			if(apr[x][j]>i){
				add(apr[x][j],i);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=head[i];j;j=nxt[j]){
			int x=ver[j];
			if(dp[i].first<dp[x].first || dp[i].first==dp[x].first && dp[i].second<=dp[x].second){
				dp[i]=dp[x];
				dp[i].second++;
				dp[i].first+=dp[i].second/mod,dp[i].second%=mod;
			}
		}
	}
	cout<<dp[n].second<<"\n";
	return 0;
}

