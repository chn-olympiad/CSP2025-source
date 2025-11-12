#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXX = 1e5 + 5, M = 1e9 +7;

string s, t, s1, s2;
int n, q, ans, pre1[MAXX], pre2[MAXX], nxt1[MAXX], nxt2[MAXX], maxx;
map<pair<string, string>, int> mp;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		mp[{s1, s2}] = 1;
		maxx = max(maxx, (int)s1.size());
	}
	while(q--){
		cin >> s >> t;
		for(int i = 0; i < s.size(); i++){
			pre1[i] = (pre1[i - 1] * 131 % M + s[i]) % M;
		} 
		for(int i = 0; i < t.size(); i++){
			pre2[i] = (pre2[i - 1] * 131 % M + t[i]) % M;
		}
		nxt1[(int)s.size()] = 0;
		for(int i = (int)s.size() - 1; i >= 0; i--){
			nxt1[i] = (nxt1[i + 1] * 131 % M + s[i]) % M;
		}
		nxt2[(int)t.size()] = 0;
		for(int i = (int)t.size() - 1; i >= 0; i--){
			nxt2[i] = (nxt2[i + 1] * 131 % M + t[i]) % M;
		}
		int N = s.size();
		N--;
		int l = 0, r = N, idl = -1, idr = n;
		while(l <= r){
			int mid = (l + r) / 2;
			if(pre1[mid] == pre2[mid]){
				idl = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			} 
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
		idl++;
		l = 0, r = N;
		while(l <= r){
			int mid = (l + r) / 2;
			if(nxt1[mid] == nxt2[mid]){
				idr = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			} 
		}
		idr--;
		int ans = 0;
		for(int i = 0; i <= idl; i++){
			s1 = "", s2 = "";
			for(int j = i; j <= N; j++){
				s1 += s[j], s2 += t[j];
				if(nxt1[j + 1] == nxt2[j + 1]) ans += mp[{s1, s2}];
				if(j - i + 1 > maxx) break;
			}
		}
		cout << ans << '\n';
	} 
	
	return 0;
} 
//°Ö°ÖÂèÂèÈ¥ÉÏ°à£¬ÎÒÉÏÓ×¶ùÔ° 
