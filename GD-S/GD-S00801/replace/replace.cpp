#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10,bs = 131,mod = 998244353;
vector<array<long long,2>> hsh[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string a,b;
		cin >> a >> b;
		long long hsh1 = 0,hsh2 = 0;
		for(size_t j = 0;j < a.size();j++){
			hsh1 = (hsh1 * bs + a[j]) % mod;
			hsh2 = (hsh2 * bs + b[j]) % mod;
		}
		hsh[a.size()].push_back({hsh1,hsh2});
	}
	for(int i = 1;i < maxn;i++)sort(hsh[i].begin(),hsh[i].end());
	while(q--){
		string s,t;
		cin >> s >> t;
		if(s.size() != t.size()){
			puts("0");
			continue;
		}
		int x = 0,y = s.size() - 1;
		while(s[y] == t[y])--y;
		while(s[x] == t[x])++x;
		long long ans = 0;	
		for(int i = x;i >= 0;i--){
			long long hsh3 = 0,hsh4 = 0;
			for(int j = i;j < y;j++){
				hsh3 = (hsh3 * bs + s[j]) % mod;
				hsh4 = (hsh4 * bs + t[j]) % mod;
			}
			for(size_t j = y;j < s.size();j++){
				hsh3 = (hsh3 * bs + s[j]) % mod;
				hsh4 = (hsh4 * bs + t[j]) % mod;
				ans += binary_search(hsh[j-i+1].begin(),hsh[j-i+1].end(),array<long long,2>{hsh3,hsh4});
			}
		}
		printf("%lld\n",ans);
	}
}
