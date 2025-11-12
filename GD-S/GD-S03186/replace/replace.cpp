#include <iostream>
#include <cstring>
#include <unordered_map>
#define int long long
using namespace std;

const int maxn=2e6+5; 
const int seed=233; 
const int mod=1e9+7; 

string a[maxn]; 
string b[maxn]; 
int l[maxn]; 
int h[maxn]; 
int n, q;

int memo[maxn]; 

int qpow(int a, int b) {
	if (memo[b]) return memo[b]; 
	
	int ret=1;
	while (b) {
		if (b&1) {
			ret *= a;
			ret %= mod; 
		}
		a *= a;
		a %= mod;
		b /= 2; 
	}
	return memo[b] = ret; 
}

char t1[maxn];
char t2[maxn]; 

int hs[maxn]; 

signed main() {
	
	freopen("replace.in", "r", stdin); 
	freopen("replace.out", "w", stdout); 
	
	cin >> n >> q;
	
	memo[0] = 1;
	for (int i=1; i<maxn; i++) memo[i] = memo[i-1]*seed*seed%mod; 
	
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		for (int j=0; j<a[i].size(); j++) {
			h[i] *= seed;
			h[i] %= mod;
			h[i] += a[i][j]-'a'; 
			h[i] *= seed;
			h[i] %= mod;
			h[i] += b[i][j]-'a'; 
			h[i] %= mod; 
		}
		l[i] = a[i].length(); 
		
//		cout << l[i] << ' ' << h[i] << endl; 
	}
	
	for (int i=1; i<=q; i++) {
		cin >> (t1+1) >> (t2+1);
		
		int m=strlen(t1+1); 
		if (m != strlen(t2+1)) {
			cout << 0 << endl;
			continue; 
		}
		
		int pre=0, suf=m+1; 
		while (pre<m && t1[pre+1] == t2[pre+1]) pre++; 
		while (suf>1 && t1[suf-1] == t2[suf-1]) suf--; 
		
//		cout << pre << ' ' << suf << endl; 
		
		int ans=0; 
		
		for (int j=1; j<=m; j++) {
			hs[j] = hs[j-1]*seed;
			hs[j] %= mod;
			hs[j] += t1[j]-'a'; 
			hs[j] *= seed;
			hs[j] %= mod;
			hs[j] += t2[j]-'a'; 
			hs[j] %= mod; 
			
			if (j < suf-1) continue; 
			for (int k=1; k<=n; k++) {
				int st=j-l[k]+1; 
				if (st <= 0) continue; 

				
				int tmp=(hs[j]-hs[st-1]*memo[l[k]]%mod+mod)%mod; 
				int tmp2=h[k]; 
				
				if (tmp != tmp2) continue; 
				if (st > pre+1) continue; 
				
				ans++; 
			}
		}
		cout << ans << endl; 
	}
	
	return 0; 
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
 
