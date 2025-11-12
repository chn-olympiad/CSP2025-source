#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define ll long long
#define MOD 998244353

unordered_map<string,int> m;

ll n,a[MAXN],b[MAXN],c[MAXN],f1[MAXN],ans=0;
bool is_all_1 = true,vis[MAXN];

void dfs(int sum,int m_num) {
	if(sum <= m_num*2) return;
	if(sum > m_num*2) {
		string s = "";
		for(int i = 1;i <= n;i++) {
			s += (vis[i]+'0');
		}
		if(!m.count(s)) {
			m[s] = true;
			ans++;
		}
	} 
	for(int i = 1;i < n;i++) {
		if(vis[i]) continue;
		vis[i] = true;
		dfs(sum-a[i],m_num);
		vis[i] = false;
	}
	vis[n] = true;
    dfs(sum-a[n],a[n-1]);
    vis[n] = false;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(ll i = 1;i <= n;i++) {	
		cin >> a[i];
		if(a[i] != 1) is_all_1 = false;
		b[i] = b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	
	if(is_all_1) {
		cout << ((n-1)*(n-2)/2) % MOD;
		return 0;
	}
	memset(vis,0,sizeof(vis));
	dfs(b[n],a[n]);
	cout << ans;
	
}
