#include<bits/stdc++.h>
using namespace std;

int n, q;
string s[200005][2];
string t[200005][2];

string replace(string a, string b, int pos, int L){
	string ans = a.substr(0, pos);
	ans += b;
	ans += a.substr(pos+L, a.size()-pos-L);
	return ans;
}

int Solve(string a, string b){
	if(a.size() != b.size()) return 0;
	int res = 0;
	int temp = 0;
	for(int i = 1; i <= n; i++){
		temp =a.find(s[i][0]);
		if(temp==-1) continue;
		if(replace(a, s[i][1], temp, s[i][1].size()) == b) res++;
	}
	return res;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	for(int i = 1; i <= q; i++) cin >> t[i][0] >> t[i][1];
	for(int i = 1; i <= q; i++){
		cout << Solve(t[i][0], t[i][1]) << endl;
	}
	return 0;
}
