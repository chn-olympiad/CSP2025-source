#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#define int long long
#define uint unsigned long long
#define N 200005
#define M 5500006
#define PII pair<int,int>
using namespace std;
int n,q;
uint seed = 213,Pow[M];
struct node{
	string before;
	string x,y;
	string after;
	uint h;
};
node s[N]; 
map<uint,int> mp;
map<uint,vector<PII>>mp2;
signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	Pow[0] = 1;
	for (int i = 1;i < M;i ++) Pow[i] = Pow[i - 1] * seed;
//	ios::sync_with_stdio(false);
//	cin.tie(0); 
	cin >> n >> q;
	for (int i = 1;i <= n;i ++) {
		string x,y;
		cin >> x >> y;
		if (x == y) continue;//保证t不相同，故s相同也无用 
		int st = 0;
		string sx = "";
		while(x[st] == y[st]) sx += x[st],st ++;
		s[i].before = sx;
		int ed = x.size() - 1;//the same size.
		sx = "";
		while(x[ed] == y[ed]) sx += x[ed],ed --;
		reverse(sx.begin(),sx.end());
		s[i].after = sx;
		sx = "";
		for (int i = st;i <= ed;i ++) sx += x[i];
		s[i].x = sx;
		sx = "";
		for (int i = st;i <= ed;i ++) sx += y[i];
		s[i].y = sx;
	}
	for (int i = 1;i <= n;i ++) {
		uint h = 0,hh = 0;
		for (int j = 0;j < s[i].before.size();j ++) h = h * seed + s[i].before[j];
		h = h * seed + ' ';
		for (int j = 0;j < s[i].x.size();j ++) h = h * seed + s[i].x[j],hh = hh * seed + s[i].x[j];
		h = h * seed + ' ';
		hh = hh * seed + ' ';
		for (int j = 0;j < s[i].y.size();j ++) h = h * seed + s[i].y[j],hh = hh * seed + s[i].y[j];
		h = h * seed + ' ';
		for (int j = 0;j < s[i].after.size();j ++) h = h * seed + s[i].after[j];
		s[i].h = h;
		mp[h] ++;
		mp2[hh].push_back({(int)s[i].before.size(),(int)s[i].after.size()});
	}
//	for (auto i : mp2) stable_sort(i.second.begin(),i.second.end());
//	for (int i = 1;i <= n;i ++) cout << s[i].h << "H\n";
//	for (int i = 1;i <= n;i ++) cout << s[i].before << ' ' << s[i].x << ' ' << s[i].y << ' ' << s[i].after << ".\n";
	for (string a,b;q --;) {
		cin >> a >> b;
		if (a.size() != b.size()) {
			puts("0");
			continue;
		}
		int st = 0;
		vector<uint> h;
		uint nh = 0;
		while(a[st] == b[st]) st ++;
		int ed = a.size() - 1;
		while(a[ed] == b[ed]) ed --;
		string sx = "";
//		reverse(sx.begin(),sx.end());
//		nh = nh * seed + ' ';
//		h.push_back(nh);
//		for (int i = st;i <= ed;i ++) nh = nh * seed + a[i],h.push_back(nh);
//		nh = nh * seed + ' ';
//		h.push_back(nh);
//		for (int i = st;i <= ed;i ++) nh = nh * seed + b[i],h.push_back(nh);
//		nh = nh * seed + ' ';
//		for (auto i : sx) nh = nh * seed + i,h.push_back(nh);
		sx = "";
		for (int i = 0;i < st;i ++) sx += a[i];
		sx += " ";
		for (int i = st;i <= ed;i ++) sx += a[i];
		sx += " ";
		for (int i = st;i <= ed;i ++) sx += b[i];
		sx += " ";
		for (int i = ed + 1;i < (int)a.size();i ++) sx += a[i];
//		cout << sx << ".\n";
		for (auto i : sx) nh = nh * seed + i,h.push_back(nh);
		uint hh = 0;
		for (int i = st;i <= ed;i ++) hh = hh * seed + a[i];
		hh = hh * seed + ' ';
		for (int i = st;i <= ed;i ++) hh = hh * seed + b[i];
		int ans = 0; 
		int t = (int)a.size() - ed - 1;
//		for (int i = 0;i <= t;i ++) {
//			int l = st - i,r = (sx.size() - ((int)a.size() - ed) + i);
//			cout << l << ' ' << r << '\n';
////			for (int i = l;i <= r;i ++) cout << sx[i];
////			cout << ".\n";
//			uint hsh;
////			for (int i = l;i <= r;i ++) hsh = hsh * seed + sx[i];
//			if (l == 0) hsh = h[r];
//			else hsh = h[r] - h[l - 1] * Pow[r - l + 1];
////			cout << hsh << '\n';
//			ans += mp[hsh];
//		}
		for (auto i : mp2[hh]) {
//			cout << i.first << '-' << i.second << '\n';
//			if (i.first > st) break;
			int l = st - i.first,r = st + 2 * (ed - st + 2) + i.second;
			if (r >= (int)sx.size()) continue;
			if (l < 0) continue;
//			cout << l << ' ' << r << '\n';
			uint hsh;
			if (l == 0) hsh = h[r];
			else hsh = h[r] - h[l - 1] * Pow[r - l + 1];
			ans += mp[hsh];
		}
//		for (int l = 0;l <= st;l ++)
//			for (int r = st + 2 * (ed - st + 2);r < sx.size();r ++) {
//				uint hsh;
//				if (l == 0) hsh = h[r];
//				else hsh = h[r] - h[l - 1] * Pow[r - l + 1];
//				ans += mp[hsh];
//			}
		printf("%lld\n",ans);
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
