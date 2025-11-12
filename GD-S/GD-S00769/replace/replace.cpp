#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 5;
int n,q,v[N],ps1[N],ps2[N],flg = 1;
ull p1[N],p2[N];
int h1[N],h2[N],ht1[N],ht2[N];
vector<int>tt1[N],tt2[N];
vector<int>vv[N];
int h[N],ht[N],hh2[N],hht2[N];
ull id(char c){
	return (ull)(c - 'a' + 1); 
}
int gh(int l,int r){
	return h[r] - h[l-1] * p1[r-l+1];
}
int ght(int x,int l,int r){
	return ht[r] - ht[l-1] * p1[r-l+1];
}
int gh2(int l,int r){
	return hh2[r] - hh2[l-1] * p2[r-l+1];
}
int ght2(int x,int l,int r){
	return hht2[r] - hht2[l-1] * p2[r-l+1];
}
string s,t;
void solve(){
//	sort(tt1.begin(),tt1.begin());
//	sort(tt2.begin(),tt2.begin());
	while (q--){
		cin >> s >> t;
		int lens = s.size(),lent = t.size();
		int poss = -1,post = -1;
		for (int j = 0;j < lens;j++){
			if (s[j] == 'b') poss = j;
			if (t[j] == 'b') post = j;
		}
//		if (poss <= posj){
//			
//		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	p1[0] = p2[0] = 1;
	for (int i = 1;i <= N - 5;i++){
		p1[i] = p1[i-1] * 233;
		p2[i] = p2[i-1] * 97;
	}
	cin >> n >> q;
	for (int j = 1;j <= n;j++){
		int cnta = 0,cntb = 0;
		cin >> s >> t;
		for (int i = 1;i <= s.size();i++){
			cnta += (s[i-1] == 'a');
			cntb += (s[i-1] == 'b');
			if (s[i-1] == 'b') ps1[i] = i-1;
			if (t[i-1] == 'b') ps2[i] = i - 1;
			h1[j] = h1[j] * 233 + id(s[i-1]);
			h2[j] = h2[j] * 97 + id(s[i-1]);
			ht1[j] = ht1[j] * 233 + id(t[i-1]);
			ht2[j] = ht2[j] * 97 + id(t[i-1]);
		}
//		if (cntb != 1 || cnta + cntb != s.size()) flg = 0;
//		if (ps1[i] > ps2[i]) tt2[ps1[j] - ps2[j]].push_back(ps2[j]);
//		else tt1[ps2[j] - ps1[j]].push_back(ps1[j]);
		vv[(int)s.size()].push_back(j);
	}
//	if (flg){
//		solve();
//		return 0;
//	}
	while (q--){
		cin >> s >> t;
		int lens = s.size(),lent = t.size();
		if (lens != lent){
			cout << "0\n";
			continue;
		}
		int l = -1,r = -1;
		for (int j = 0;j < lens;j++){
			if (s[j] != t[j]){
				if (l == -1) l = j;
				else r = j;
			}
			h[j+1] = h[j] * 233 + id(s[j]);
			ht[j+1] = ht[j] * 233 + id(t[j]);
			h2[j+1] = h2[j] * 97 + id(s[j]);
			ht2[j+1] = ht2[j] * 97 + id(t[j]);
		}
//		cout << l << " " << r << endl;
		int anss = 0;
		for (int i = 0;i <= l;i++){
			for (int j = r;j < lens;j++){
				for (auto k : vv[j-i+1]){
//					cout << i+1 << ' ' << j+1<<endl;
//					cout <<  gh(i+1,j+1) << " " << h1[k] << "   " <<ght(k,i+1,j+1) << ht1[k] << endl;
					if (gh(i+1,j+1) == h1[k] && ght(k,i+1,j+1) == ht1[k] && gh2(i+1,j+1) == hh2[k] && ght2(k,i+1,j+1) == hht2[k]) anss++;
				}
			}
		}
		cout << anss << '\n';
//		cout << endl;
	}
	return 0;
}












