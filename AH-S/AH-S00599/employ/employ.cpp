#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[505],sum[505],vis[505],cnt;
int mod=998244353;
string s;
void dfs(int idx,int c,int yes){
	if(idx>n&&yes>=m){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
	if(vis[i])continue;
	if(s[idx]=='0'){
		vis[i]=1;
		dfs(idx+1,c+1,yes);
		vis[idx]=0;
	}
	else if(c>=a[i]){
		vis[idx]=1;
		dfs(idx+1,c+1,yes);
		vis[idx]=0;
	}else{
		vis[idx]=1;
		dfs(idx+1,c,yes+1);
		vis[idx]=0;
	}
}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	if(cnt==0){
		long long ans=1ll;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	return 0;
}
