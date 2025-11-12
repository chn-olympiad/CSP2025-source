#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
vector<int>g[maxn];
int dp[maxn],n,k,a[maxn],s[maxn],in[maxn],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				for(int t=j+1;t<=n+1;t++){
				//	if(i==1) cout<<t<<' ';
					g[i].push_back(t);
					in[t]++;
				}
				break;
			}
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!in[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			dp[v]=max(dp[u]+1,dp[v]);
			in[v]--;
			if(!in[v]) q.push(v);
		}
	}
	for(int i=1;i<=n+1;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
