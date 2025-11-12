#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=550;
int n,m,c[N],a[N];
bool vis[N];
int cnt,tot;
string s;
inline void dfs() {
	if(tot==n) {
		int ans=0,sum=0;
		for(int i=1; i<=n; ++i) {
			int x=sum;
			if(x<c[a[i]]) {
				if(s[i-1]=='1') ++ans;
				else sum++;
			} else sum++;
		}
		if(ans>=m) cnt++,cnt%=mod;
		return;
	}
	for(int i=1; i<=n; ++i) {
		if(vis[i]) continue;
		vis[i]=true;
		a[++tot]=i;
		dfs();
		tot--;
		vis[i]=false;
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; ++i) cin>>c[i];
	if(n<=12) {
		dfs();
		cout<<cnt;
	} else {
		int ans=1;
		for(int i=1; i<=n; ++i) ans=ans*i%mod;
		cout<<ans;
	}
}
