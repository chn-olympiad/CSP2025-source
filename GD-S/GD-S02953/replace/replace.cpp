#include<bits/stdc++.h>
#define mod 998244353
#define pii pair<int, int>
using namespace std;
const int N = 5e6+5;
int n, q, l[N], hsh[N], hsh2[N];
char s[N], t[N];
map<int, vector<int> > mp;
pii hashs(int l, int r){
	pii ans = {0, 0};
	for(int i = l; i <= r; i++) ans.first = (131ll*(ans.first)+s[i])%mod; 
	for(int i = l; i <= r; i++) ans.second = (131ll*(ans.second)+t[i])%mod;
	return ans;
}
int h[N], ht[N], pw[N];
int getlr(int l, int r){
	return ((h[r]-1ll*h[l-1]*pw[r-l+1]%mod)%mod+mod)%mod;
}
int getlr2(int l, int r){
	return ((ht[r]-1ll*ht[l-1]*pw[r-l+1]%mod)%mod+mod)%mod;
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	int cnt = 0, rs = 0;
	for(int i = 1; i <= n; i++){
		scanf("%s", s+1), scanf("%s", t+1);
		l[i] = strlen(s+1);
		rs = max(rs, l[i]);
		int L = l[i]+1, R = 0;
		for(int j = 1; j <= l[i]; j++) if(s[j] != t[j]){
			L = j;
			break;
		}
		for(int j = l[i]; j >= 1; j--) if(s[j] != t[j]){
			R = j;	
			break;
		} pii tmp = hashs(1, l[i]);
		hsh[i] = tmp.first, hsh2[i] = tmp.second; 
//		cout << L << " " << R << '\n';
		if(L > R){
			mp[0].push_back(i);
		} else{
			pii x = hashs(L, R);
			mp[x.first].push_back(i);
		}
	} pw[0] = 1;
	for(int i = 1; i <= rs; i++) pw[i] = pw[i-1]*131ll%mod;
	for(int i = 1; i <= q; i++){
		scanf("%s", s+1), scanf("%s", t+1);
		int len = strlen(s+1);
		int L = l[i]+1, R = 0;
		for(int j = 1; j <= len; j++) if(s[j] != t[j]){
			L = j;
			break;
		}
		for(int j = len; j >= 1; j--) if(s[j] != t[j]){
			R = j;	
			break;
		}
		for(int j = 1; j <= len; j++) h[j] = (h[j-1]*131ll+s[j])%mod;
		for(int j = 1; j <= len; j++) ht[j] = (ht[j-1]*131ll+t[j])%mod;
		if(L > R){
			int ans = 0;
			for(auto x:mp[0]){
				for(int j = 1; j+l[x]-1 <= len; j++){
					if(getlr(j, j+l[x]-1) == hsh[x]){
						ans++;
					}
				}
			}
			cout << ans << '\n';
		} else{
			if(R-L+1 > rs){
				cout << "0\n";
				continue;
			}
			int ans = 0;
			for(auto x:mp[getlr(L, R)]){
				for(int j = 1; j+l[x]-1 <= len; j++){
					if(getlr(j, j+l[x]-1) == hsh[x] && getlr2(j, j+l[x]-1) == hsh2[x]){
						ans++;
					}
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
