#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353,maxn=509;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;cin>>n>>m;
	string s;cin>>s;
	vector<int>a(n+1),D(a),vis(a);
	vector<int>fc(n+1,1),R(n+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i-1]-'0',(fc[i]=fc[i-1]*i)%=mod;
	for(int i=1;i<=n;i++)cin>>D[i];
	function<void(int,int)>dfs=[&](int u,int cnt){
		if(u>n){
			if(n-cnt>=m)(ans+=1)%=mod;
			return;
		}
		int k=u-cnt-1;
		if(k>=m){
			ans+=fc[n-u+1];
			return;
		}
		if(k+(n-u+1)<m)return;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			vis[i]=1;
			if(cnt>=D[i] or !a[u])
				dfs(u+1,cnt+1);
			else dfs(u+1,cnt);
			vis[i]=0;
		}
	};
	dfs(1,0);
	cout<<ans%mod;
	/*
	求出每个人的DDL(无人放弃时正常面试)
	dp[i][j]表示前i录j，不允许有人放弃时的排列数。
	dp[i][j]=dp[k][j-1]*(S[i]-j+1).
	考虑加上放弃怎么做？	
	
	兴戈止战，愿天下再无烽火。 
	*/ 
	return 0;
} 
