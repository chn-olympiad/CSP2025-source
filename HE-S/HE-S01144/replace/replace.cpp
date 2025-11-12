#include <bits/stdc++.h>
using namespace std;
const int _ = 100010, __ = 100010, P = 1331;
int n, q, lena[_], lenb[_], ca, cb, ans;
string sa, sc, ta, tb;
unsigned long long ha[_], hb[_], p[__], hs[__], hz[__];
inline bool suan(int l, int r){
	if(l > r){
		return 1;
	}
	return hs[r] - hs[l - 1] * p[r - l] == hz[r] - hz[l - 1] * p[r - l];
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
	p[1] = P;
	for(int i = 2; i <= 100000; i ++){
		p[i] = p[i - 1] * P;
	}
	ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		cin >> sa >> sc;
		ca = sa. size();
		lena[i] = ca;
		for(int j = 1; j <= ca; j ++){
			ha[i] = ha[i] * P + sa[j] - 'a' + 1;
		}
		ca = sc. size();
		lenb[i] = ca;
		for(int j = 0; j < ca; j ++){
			hb[i] = hb[i] * P + sc[j] - 'a' + 1;
		}
	}
	for(int i = 1; i <= q; i ++){
		ans = 0;
		cin >> ta >> tb;
		ca = ta. size();
		cb = tb. size();
		if(ca != cb){
			cout << 0 << '\n';
			continue;
		}
		for(int j = 1; j <= ca; j ++){
			hs[j] = hs[j - 1] * P + ta[j - 1] - 'a' + 1;
		}
		for(int j = 1; j <= cb; j ++){
			hz[j] = hz[j - 1] * P + tb[j - 1] - 'a' + 1;
		}
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= ca - lena[i] + 1; j ++){
				int k = j + lena[i] - 1;
				if(suan(1, j - 1) && suan(k + 1, ca)){
					ans ++;
					j = ca - lena[i] + 2;
				}
			}
		}
		cout << ans<< endl;
	}
	return 0;
}
