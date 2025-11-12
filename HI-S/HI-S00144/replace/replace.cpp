#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, k, w) for(int (i) = (j); ((w) > 0) ? ((i) <= (k)) : ((i) >= (k)); (i) += (w))
const int N = 5e6 + 5, mod = 1e9 + 7;
ll n, q, m, len[N], p[N][3], hs[N][3], pw[N];
string s[N][3], t1, t2;
vector<int> dp[2 * N];
ll hs1[N], hs2[N];
ll solve(){
	ll p1 = 0, p2 = 0, f, k;
	rep(i, 1, m, 1){
		if(t1[i] == 'b')p1 = i;
		if(t2[i] == 'b')p2 = i;
	}
	f = p2 - p1;
	k = m - p1;
	ll p = upper_bound(dp[f + N].begin(), dp[f + N].end(), k) - dp[f + N].begin();
	return p;
}
ll solve1(){
	ll ans = 0;
	rep(i, 1, n, 1){
		rep(j, 0, len[i] - 1, 1){
			hs[i][1] = (hs[i][1] * 26 % mod + s[i][1][j] - 'a') % mod;
			hs[i][2] = (hs[i][2] * 26 % mod + s[i][2][j] - 'a') % mod;
		}
	}
	rep(j, 1, m, 1){
		hs1[j] = (hs1[j - 1] * 26 % mod + t1[j] - 'a') % mod;
		hs2[j] = (hs2[j - 1] * 26 % mod + t2[j] - 'a') % mod;
	} 
	rep(j, 1, m, 1){
		rep(i, 1, n, 1){
			if(hs1[j + len[i] - 1] - hs1[j - 1] * pw[len[i]] == hs[i][1] && hs2[j + len[i] - 1] - hs2[j - 1] * pw[len[i]] == hs[i][2])ans++; 
		}
		if(t1[j] != t2[j])break;
	}
	return ans;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	bool f = 0;
	rep(i, 1, N - 5, 1)pw[i] = pw[i - 1] * 26 % mod;
	rep(i, 1, n, 1){
		cin >> s[i][1] >> s[i][2];
		len[i] = s[i][1].size();
		rep(j, 0, len[i - 1], 1)if(s[i][1][j] != 'a' && s[i][1][j] != 'b' && s[i][2][j] != 'a' && s[i][2][j] != 'b')f = 1; 
	}
	if(!f){
		cin >> t1 >> t2;
		m = t1.size();
		t1 = " " + t1, t2 = " " + t2;
		cout << solve1() << "\n";
		return 0;
	} 
	rep(i, 1, n, 1){
		rep(j, 0, len[i] - 1, 1){
			if(s[i][1][j] == 'b')p[i][1] = j;
			if(s[i][2][j] == 'b')p[i][2] = j;
		}
		dp[p[i][2] - p[i][1] + N].push_back(len[i] - 1 - p[i][1]);
	}
	rep(i, 1, n, 1){
		sort(dp[p[i][2] - p[i][1] + N].begin(), dp[p[i][2] - p[i][1] + N].end());
	}
	while(q--){
		cin >> t1 >> t2;
		m = t1.size();
		t1 = " " + t1, t2 = " " + t2;
		cout << solve() << "\n";
	}
	return 0;
}

