#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int mod=998244353;
int n,m;
int f=0;
string s;
int c[maxn];
bool vis[maxn];
long long dp[maxn][maxn];
long long ans=0;
long long ksm(int x){
	long long ans=1;
	for(long long i=1;i<=x;i++){
		ans=ans*i;
		ans%=mod;
	}
	return ans;
}
long long dfs(int i,int j){
	if(i==n&&j<=n-m){
		ans++;
		return 0;
	}
	if(i==n)return 0;
	for(int p=1;p<=n;p++){
		if(vis[p]==1)continue;
		vis[p]=1;
		if(c[p]<=j||s[i]=='0'){
			dfs(i+1,j+1);
		}else{
			dfs(i+1,j);
		}
		vis[p]=0;
	}
	return 0;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int u=1;
	int len=s.size();
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<len;i++){
		if(s[i]=='0')u=0;
	}
	if(u){
		cout<<ksm(n);
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0; 
}
