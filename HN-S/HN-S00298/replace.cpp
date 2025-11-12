#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int base = 31;
int siz[100010], Hash1[100010], Hash2[100010], Hashs[100010], Hasht[100010], Pow[100010];
int gets(int l, int r){
	return Hashs[r] - Hashs[l - 1] * Pow[r - l];
}
int gett(int l, int r){
	return Hasht[r] - Hasht[l - 1] * Pow[r - l];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s, s1;
		cin >> s >> s1;
		siz[i] = s.size();
		s = " " + s, s1 = " " + s1;
		for(int j = 1; j <= siz[i]; j ++){
			Hash1[i] = Hash1[i] * base + s[j] - 'a' + 1;
			Hash2[i] = Hash2[i] * base + s1[j] - 'a' + 1;
		} 
	}
	while(q --){
		string s, t;
		cin >> s >> t;
		int Siz = s.size();
		s = " " + s, t = " " + t;
		int Top = 0, End = 0;
		for(int i = 1; i <= Siz; i ++){
			if(s[i] == t[i]) Top = i;
			else break;
		}
		for(int i = Siz; i >= 1; i --){
			if(s[i] == t[i]) End = i;
			else break;
		}
		Pow[0] = 1;
		for(int i = 1; i <= Siz; i ++){
			Hashs[i] = Hashs[i - 1] * base + s[i] - 'a' + 1;
			Hasht[i] = Hasht[i - 1] * base + t[i] - 'a' + 1;
			Pow[i] = Pow[i - 1] * base;
		}
		int Ans = 0;
		for(int i = 1; i <= Top + 1; i ++){
			for(int j = 1; j <= n; j ++){
				if(i + siz[j] - 1 >= End - 1){
					if(gets(i, i + siz[j] - 1) == Hash1[j] && gett(i, i + siz[j] - 1) == Hash2[j]) ++ Ans;
				}
			}
		}
		cout << Ans << '\n';
	}
}
