#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
const int INF = 1e9+7;
const ll LLINF = (ll)1e18+7;
const lf LFINF = (lf)1e18+7;
const int maxn = 2e5+5;
const int maxm = 2e5+5;
const ll hashmod = 1234567891;
const ll maxl = 5e6+5;
const ll base = 31;
int T, N, M, K, Q;
vector<ll> h[maxn][2];
ll h2[maxl], h3[maxl];
int L[maxn], R[maxn], sz[maxn];
ll powbase[maxl];

bool inline isdig(const char &ch){
	return ch >= '0' && ch <= '9';
}

ll hashval(const string &s, int l, int r){
	ll res = 0;
	for (int i = l; i <= r; i++){
		res = (res*base%hashmod + s[i]-'a'+1)%hashmod;
	}
	return res;
}

template <typename type>
void inline read(type &x){
	x = 0; type f = 1;
	char ch = getchar();
	while (!isdig(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdig(ch)) x = x*10+ch-'0', ch = getchar();
	x = x*f;
} 



ll gethash(ll *h, int l, int r){
	return (h[r] - h[l]*powbase[r-l]%hashmod + hashmod) % hashmod;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	powbase[0] = 1;
	for (int i = 1; i <= 5e6; i++) powbase[i] = powbase[i-1]*base%hashmod;
	ios::sync_with_stdio(false);
	cin>>N>>Q;
	for (int i = 1; i <= N; i++){
		string a, b;
		cin>>a>>b;
		
		h[i][0].resize(a.size());
		h[i][1].resize(b.size());
		int l = 0, r = a.size()-1;
		while (l <= r && a[l] == b[l]) l++;
		while (r >= l && a[r] == b[r]) r--;
		if (l > r) continue;
		L[i] = l, R[i] = r; sz[i] = b.size();
		
		int siz = a.size();
		for (int j = 0; j < siz; j++){
			if (j == 0){
				h[i][0][0] = a[0]-'a'+1;
				h[i][1][0] = b[0]-'a'+1;
			}else{
				h[i][0][j] = (h[i][0][j-1]*base%hashmod + a[i]-'a'+1)%hashmod;
				h[i][1][j] = (h[i][1][j-1]*base%hashmod + b[i]-'a'+1)%hashmod;
			}
		}
	}
	
	for (int i = 1; i <= Q; i++){
		string a, b;
		cin>>a>>b;
		if (a.size() != b.size()){
			cout<<0<<"\n";
			continue;
		}
		
		int l = 0, r = a.size()-1;
		while (l <= r && a[l] == b[l]) l++;
		while (r >= l && a[r] == b[r]) r--;
		
		int siz = a.size();
		for (int i = 0; i < siz; i++){
			if (i == 0){
				h2[i] = a[0]-'a'+1;
				h3[i] = b[0]-'a'+1;
			}else{
				h2[i] = (h2[i-1]*base%hashmod + a[i]-'a'+1)%hashmod;
				h3[i] = (h3[i-1]*base%hashmod + b[i]-'a'+1)%hashmod;
			}
		}
		
		int res = 0;
		for (int i = 1; i <= N; i++){
			if (r-l+1 != R[i]-L[i]+1) continue;
			if (l-L[i] < 0 || sz[i]-R[i] > siz - r) continue;
			
//			printf("%lld %lld\n", h[i][0][sz[i]-1], gethash(h2, l-L[i], r-L[i]+sz[i]-1));
			if (h[i][0][sz[i]-1] == gethash(h2, l-L[i], r-L[i]+sz[i]-1) && h[i][1][sz[i]-1] == gethash(h3, l-L[i], r-L[i]+sz[i]-1)) res++;

		}
		cout<<res<<"\n";
	}
	
	
	return 0;
}
