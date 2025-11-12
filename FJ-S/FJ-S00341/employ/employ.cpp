//CSP-S AK me
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m,c[505],cnt=0;
vector<int> v;
bool vis[505];
string s;
void dfs(int k){
	if(k==n){
		int pre=0;
		for(int i=1;i<=n;i++){
			if(c[v[i-1]]<=pre || s[i]=='0'){
				pre++;
			}
		}
		if(n-pre>=m) cnt=(cnt+1)%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		v.push_back(i);
		dfs(k+1);
		vis[i]=0;
		v.pop_back();
	}
}
signed main(){
//	freopen("empoly.in","r",stdin);
//	freopen("empoly.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(0);
	cout<<cnt;
	return 0;
}
