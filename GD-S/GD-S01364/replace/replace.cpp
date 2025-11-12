#include<bits/stdc++.h>
#define up(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define dn(i, a, b) for(int i = (int)a; i >= (int)b; --i)
#define vc vector
#define pb push_back
#define pii pair<int, int>
#define x first
#define y second
#define ll long long

using namespace std;

const int MN = 2e5 + 5;
const int M1 = 1e9 + 7;
ll fac(ll a, int b){
	ll res = 1;
	for(; b; b >>= 1, a = a * a % M1) if(b & 1) res = res * a % M1;
	return res;
}

char s[5000005];
int n, m, len[MN];
ll inv[MN], a[MN];
map<int, bool> cnt;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	inv[0] = 1;
	ll fc = 1;
	up(i, 1, 2e5){
		fc = fc * 901 % M1;
		inv[i] = fac(fc, M1 - 2);
	}
	scanf("%d%d", &n, &m);
	up(i, 1, n){
		scanf("%s", s + 1);
		int k = strlen(s + 1), v1 = 0;
		len[i] = k;
		vc<char> s1, s2; s1.pb(0), s2.pb(0);
		up(j, 1, k) s1.pb(s[j]);
		scanf("%s", s + 1);
		up(j, 1, k) s2.pb(s[j]);
		up(j, 1, k){
			int w = (s1[j] - 'a' + 1) * 29 + (s2[j] - 'a' + 1);
			a[i] = (a[i] * 901 + w) % M1;
		}
	}
	while(m--){
		cnt.clear();
		int ans = 0;
		scanf("%s", s + 1);
		int k = strlen(s + 1), v1 = 0;
		vc<char> s1, s2; s1.pb(0), s2.pb(0);
		up(j, 1, k) s1.pb(s[j]);
		scanf("%s", s + 1);
		if((int)strlen(s + 1) != k){
			puts("0");
			continue;
		}
		up(j, 1, k) s2.pb(s[j]);
		int L = 0, R = 0;
		up(j, 1, k){
			if(L == 0 && s1[j] != s2[j]) L = j;
			if(s1[j] != s2[j]) R = j;
		}
		ll vl = 0;
		cnt[0] = 1;
		up(i, 1, k){
			int w = (s1[i] - 'a' + 1) * 29 + (s2[i] - 'a' + 1);
			vl = (vl * 901 + w) % M1;
			if(i < L){
				cnt[vl] = 1;
			}
			if(i >= R){
				up(j, 1, n){
//					if(j == 1) printf("FK: %lld %lld\n", vl, a[j]);
					if(cnt[(vl - a[j] + M1) * inv[len[j]] % M1]) ans++;
				}
			}
		}
		printf("%d\n", ans);
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
	return 0;
}
