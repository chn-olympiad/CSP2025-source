#include <bits/stdc++.h>
#define N 5005
#define mod 998244353

using namespace std;

int n, a[N], ans;
bool b[N];

vector<int> v;
map<vector<int>, bool> mp;

void print() {
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	puts("");
}

void dfs() {
	sort(v.begin(), v.end() );
	if(mp[v]) return ;
	mp[v] = 1;
	if(v.size() > 2) {
		int mx = 0, sum = 0;
		for(int i = 0; i < v.size(); i++) {
			mx = max(mx, a[ v[i] ]);
			sum += a[ v[i] ];
		}
		if(sum > mx * 2) ans ++;
	}
	ans %= mod;
	for(int i = 1; i <= n; i++) {
		if(b[i]) continue;
		vector<int> _;
		for(int j = 0; j < v.size(); j++)
		_.push_back(v[j]);
		v.push_back(i);
		b[i] = 1;
		dfs();
		v.clear();
		for(int j = 0; j < _.size(); j++)
		v.push_back(_[j]);
		b[i] = 0;
	}
}

int rd() {
	int S = 0, F = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') F = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		S = (S << 3) + (S << 1) + (ch ^ 48);
		ch = getchar();
	}
	return S * F;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = rd();
	for(int i = 1; i <= n; i++) a[i] = rd();
	for(int i = 1; i <= n; i++) {
		v.clear();
		v.push_back(i);
		b[i] = 1;
		dfs();
		b[i] = 0; 
	}
	printf("%d", ans);
	return 0;
}
/*
20·Ö 
*/
