#include<bits/stdc++.h>
#define PII pair<long long,long long>
using namespace std;
typedef long long ll;
const int N = 1e5 + 100;
const ll mod = 998244353;
ll n,m,a[510],ans,cnt,f[510][510][2],g[510][510][2];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	ans = 1;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] == 0) ++cnt;
	} 
	if(m == cnt){
		for(int i = 1; i <= m - cnt; ++i){
			ans = ans * (cnt - i + 1) % mod;
		}
		for(int i = m - cnt + 1; i <= n; ++i){
			ans = ans * (n-i+1) % mod;
		}		
	}else{
		
	}
	ans %= mod;
	cout << ans;
	return 0;
}
