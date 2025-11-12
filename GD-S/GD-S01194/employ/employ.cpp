#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=507,mod=998244353;
int n,m;
int dp[N];
string s;
int a[N];
int sum[N];
bool v[N];
ll ans=0;
void dfs(int t,int k){
	if(t==n+1){
		if(k>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(s[i]=='0') dfs(t+1,k);
			else if(sum[t]>=a[i]) dfs(t+1,k);
			else dfs(t+1,k+1);
			v[i]=0;
		}
	}
	return;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(s[i]=='0') sum[i]++;
		sum[i]+=sum[i-1];
	}
	dfs(1,0);
	cout<<ans%mod;
	return 0;
} 
