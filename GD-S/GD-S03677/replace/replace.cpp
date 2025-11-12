#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<queue>
#define ull long long
using namespace std;

const long long MOD = 1e9 + 9;
const int MAXN = 5e6 + 5;
map<pair<ull,ull>,int> mp;
ull h1[MAXN],h2[MAXN];
ull Pow[MAXN];
int n,q;
ull get(const string &m){
	ull ans = 0;
	for(auto ch : m) ans = (ans * 29 + (ch - 'a' + 1)) % MOD;
	return ans;
}
ull calc(ull h[],int l,int r){if(l > r) return 0;return ((h[r] - h[l-1] * Pow[r-l+1]) % MOD + MOD) % MOD;}
void solve(){
	string a,b;
	cin >> a >> b;
	// cout << a << ' ' << b << '\n';
	int n = a.size();
	h1[0] = h2[0] = 0;
	for(int i = 1;i <= n;i++) h1[i] = (h1[i-1] * 29 + (a[i-1] - 'a' + 1)) % MOD;
	for(int i = 1;i <= n;i++) h2[i] = (h2[i-1] * 29 + (b[i-1] - 'a' + 1)) % MOD;
	long long ans = 0;
	// cout << calc(h1,1,n) << ' ' << calc(h2,1,n) << '\n';
	// cout << st.count({calc(h1,1,n),calc(h2,1,n)}) << '\n';
	for(int i = 0;i <= n;i++)
		for(int j = i;j <= n;j++){
			if(calc(h1,1,i) == calc(h2,1,i) && calc(h1,j+1,n) == calc(h2,j+1,n) && mp.count({calc(h1,i+1,j),calc(h2,i+1,j)}))
				ans += mp[{calc(h1,i+1,j),calc(h2,i+1,j)}];//,cout << i << ' ' << j << '\n';
		}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	Pow[0] = 1;
	for(int i = 1;i <= 5e6;i++) Pow[i] = Pow[i-1] * 29 % MOD;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		mp[{get(s1),get(s2)}]++;
	}
	while(q--) solve();
	return 0;
}