#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],ans;
string s;
bool vis[N];
void dfs(int now,int sum) {
	if(now>n) {
		if(n-sum>=m) ++ans;
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue ;
		vis[i]=1;
		if(s[now]=='0') {
			dfs(now+1,sum+1);
		} else {
			if(sum>=c[i]) dfs(now+1,sum+1);
			else dfs(now+1,sum);
		}
		vis[i]=0;
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) {
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	sort(c+1,c+n+1);
	ans=1;
	int sum=1;
	for(int i=n;i>=1;i--) {
		if(c[i]>=i) ans=0;
		else ans=ans*(i-c[i])%mod;
		sum=sum*i%mod;
	}
	ans=(sum-ans+mod)%mod;
	cout<<ans;
	return 0;
}

