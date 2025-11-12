#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e3+5;
const long long mod=998244353;
int n,m,k;
int T;
int c[N];
int p[N];
string s;
int vis[N];
int ans;
int cnt;
void dfs(int x){
	if(x==n+1){
		int last=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')last++;
			else if(last>=c[p[i]])last++;
			else cnt++;
		}
		if(cnt>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		p[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	//ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)if(s[i]=='1')cnt++;
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(cnt==n){
		long long ans=1;
		for(int i=2;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	cout<<0;
}
