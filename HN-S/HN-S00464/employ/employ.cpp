#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=107;
const int mod=998244353;
int n,m;
string s;
int ans=0;
int a[maxn];
int p[maxn];
bool vis[maxn];
void dfs(int x){
	if(x>n){
		int cnt=0,cntz=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[p[i]]){
				cnt++;
				continue;
			}
			if(s[i]=='1'){
				cntz++;
			}
			else{
				cnt++;
			}
		}
		if(cntz>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		p[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
	return ;
}
void solve(){
	int len=s.size();
	for(int i=1;i<len;i++){
		if(s[i]=='0'){
			cout<<0;
			return ;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cout<<0;
			return ;
		}
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=mod;
	}
	cout<<sum;
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool flag=1;
	cin>>n>>m;
	cin>>s;
	s="#"+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		solve();
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
