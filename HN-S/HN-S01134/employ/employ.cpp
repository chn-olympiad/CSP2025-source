#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[1000005],dp[(1ll<<18)][19],sum[1000005],ans,S;
string s;
// int query(int l,int r){
// 	if(!l) return sum[r];
// 	return sum[r]-sum[l-1];
// }
// vector<int> v;
// bool vis[18];
// void help(){
// 	int cnt=0;
// 	for(int i=0; i<v.size(); i++) if(vis[i]) cnt++;
// 	// cout<<"addd\n";
// 	if(cnt<m) return;
// 	int s=1,sum=0;
// 	for(int i=0; i<v.size(); i++){
// 		if(vis[i]==0){
// 			int cnt=v[i]-i-1;
// 			for(int j=0; j<i; j++) if(vis[j]==0) cnt++;
// 			(s*=max(0ll,query(0,cnt)-sum))%=mod;
// 			// if(cnt==4) cout<<"addd "<<s<<'\n';
// 		}
// 			sum++;
// 	}
// 	cout<<"addd"<<cnt<<' '<<s<<' '<<S<<'\n';
// 	for(int i=0; i<v.size(); i++) cout<<vis[i]<<' ';
// 	cout<<'\n';
// 	sum=0;
// 	for(int i=v.size()-1; i>=0; i--){
// 		if(vis[i]==1){
// 			int cnt=v[i]-i-1;
// 			for(int j=0; j<i; j++) if(vis[j]==0) cnt++;
// 			// cout<<i<<' '<<cnt<<' '<<query(cnt+1,n)-sum<<'\n';
// 			(s*=max(0ll,query(cnt+1,n)-sum))%=mod;
// 			// if(cnt==4) cout<<"addd "<<s<<'\n';
// 		}
// 			sum++;
// 	}
// 	(ans+=s*S)%=mod;
// 	cout<<cnt<<' '<<s<<' '<<S<<'\n';
// 	return;
// }
// void dfs(int cur){
// 	if(cur==v.size()){help();return;}
// 	vis[cur]=true,dfs(cur+1),vis[cur]=false,dfs(cur+1);
// 	return;
// }
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1; i<=n; i++) cin>>c[i];
	if(n==m){
		int cnt=0;
		for(int i=1; i<=n; i++) if(s[i]=='0') cnt++;
		for(int i=1; i<=n; i++) if(!c[i]) cnt++;
		if(!cnt){
			int s=1;
			for(int i=1; i<=n; i++) (s*=i)%=mod;
			cout<<s<<'\n';
		}
		else cout<<"0\n";
		return 0;
	}
	else if(n<=18){
		dp[0][0]=1;
		for(int i=0; i+1<(1ll<<n); i++){
			int sum=__builtin_popcount(i);
			for(int j=0; j<=n; j++) for(int k=1; k<=n; k++){
				if((i>>k-1)&1ll) continue;
				(dp[i|(1ll<<k-1)][j+(c[k]<=j||s[sum+1]=='0')]+=dp[i][j])%=mod;
			}
		}
		int ans=0;
		for(int i=0; i<=n-m; i++) (ans+=dp[(1ll<<n)-1][i])%=mod;
		cout<<ans;
	}
	// else{
		// for(int i=1; i<=n; i++) sum[c[i]]++;
		// for(int i=1; i<=n; i++) sum[i]+=sum[i-1];
		// for(int i=1; i<=n; i++) if(s[i]=='1') v.push_back(i);
		// S=1;
		// for(int i=1; i<=n-v.size(); i++) (S*=i)%=mod;
		// dfs(0);
		// cout<<ans;
	// }
	return 0;
}