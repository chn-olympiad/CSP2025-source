#include <bits/stdc++.h>
#define ll long long
#define maxn 510
using namespace std;

const ll mod=998244353;

ll c[maxn],p[maxn];
bool s[maxn],used[maxn];
ll n,m,ans;

bool sol() {
	ll cntno=0;
	for (int i=1;i<=n;i++) {
		if (!s[i]||cntno>=c[p[i]]) {
			cntno++;
		}
	}
	if (n-cntno>=m) return 1;
	else return 0;
}

void dfs(ll x) {
	if (x>n) {
		if (sol()==1) {
			ans++;
		}
		return;
	}
	for (int i=1;i<=n;i++) {
		if (!used[i]) {
			p[x]=i;
			used[i]=1;
			dfs(x+1);
			used[i]=0;
		}
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	string S;
	cin>>S;
	for (int i=1;i<=S.size();i++) {
		if (S[i-1]=='0') s[i]=0;
		else s[i]=1;
	}
	for (int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans%mod;
	return 0;
}
