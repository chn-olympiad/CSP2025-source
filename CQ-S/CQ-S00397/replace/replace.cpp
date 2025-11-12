#include <bits/stdc++.h>
using namespace std;
const int N = 200060;
int n, m;
bool v = 1, v2 = 1;
string a1[N], a2[N];
string xx11[N], yy11[N];
map<string, int> mp;
struct BB{
	int d, l, r;
}q[N], t[N];
void checkB(string xx11){
	int t = 0;
	for(int i = 0; i < xx11.size(); i++){
		if(xx11[i] == 'b'){
			t++;
			if(t > 1){
				v = 0;
				return;
			}
		}
		else if(xx11[i] != 'a'){
			v = 0;
			return;
		}
	}
	if(!t) v = 0;
	return;
}
string sm1[2050], sm2[2050];
int d(string xx11, string yy11){
	if(mp.find(xx11 + yy11) != mp.end()) return mp[xx11 + yy11];
	return 0;
}
int findB(string xx11){
	for(int i = 0; i < xx11.size(); i++)
		if(xx11[i] == 'b') return i;
}
int f1(string xx11, string yy11){
	int res = 0, l = -1, r;
	string s1 = "", s2 = "";
	for(int i = 0; i < xx11.size(); i++)
		if(xx11[i] != yy11[i]){
			r = i;
			if(l == -1) l = i;
		}
	for(int i = l; i <= r; i++) s1 += xx11[i], s2 += yy11[i];
	res += d(s1, s2);
	sm1[0] = "", sm2[0] = "";
	for(int i = 1; r + i < xx11.size(); i++)
		sm1[i] = sm1[i - 1] + xx11[r + i], sm2[i] = sm2[i - 1] + yy11[r + i];
	for(int i = 1; l - i >= 0; i++){
		s1 = xx11[l - i] + s1, s2 = yy11[l - i] + s2;
		for(int j = 0; r + j < xx11.size(); j++){
			res += d(s1 + sm1[j], s2 + sm2[j]);
		}	
	}	
	return res;
}


void init(){
	for(int i = 1; i <= n; i++){
		int aa = findB(a1[i]), bb = findB(a2[i]);
		t[i] = (BB){bb - aa, min(aa, bb), min(a1[i].size() - aa, a1[i].size() - bb) - 1};
	}
	for(int i = m; i <= m; i++){
		int aa = findB(xx11[i]), bb = findB(yy11[i]);
		q[i] = (BB){bb - aa, min(aa, bb), min(xx11[i].size() - aa, xx11[i].size() - bb) - 1};
	}
}
int fB(int tt){
	int res = 0;
	for(int i = 1; i <= n; i++)
		if(q[tt].l >= t[i].l && q[tt].r >= t[i].r && q[tt].d == t[i].d) res++;
	return res;
}
int main(){//15?
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a1[i] >> a2[i];
		checkB(a1[i]); checkB(a2[i]);
	}
	
	for(int i = 1; i <= m; i++){
		cin >> xx11[i] >> yy11[i];
		checkB(xx11[i]); checkB(yy11[i]);
		if(xx11[i].size() > 300) v2 = 0;
	}
	if(v2){
		for(int i = 1; i <= n; i++)
			if(n <= 200)mp[a1[i] + a2[i]]++;
		for(int i = 1; i <= m; i++)
			cout <<  f1(xx11[i], yy11[i]) << '\n';
	}
	else if(v){
		init();
		for(int i = 1; i <= m; i++)
			cout << fB(i) << '\n';
	}
	else{
		for(int i = 1; i <= n; i++)
			if(n <= 200)mp[a1[i] + a2[i]]++;
		for(int i = 1; i <= m; i++)
			cout <<  f1(xx11[i], yy11[i]) << '\n';
	}
	return 0;
}
