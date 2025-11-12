#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int n, q, l[N], r[N];
long long p1 = 131, p2 = 127, md1 = 1e9+7, md2 = 987654323;
//string a[N], b[N];
struct Node{
	int x, y;
};
bool cmp(Node u, Node v){
	return u.x < v.x;
}
int getHash(string x, string y){
	long long ans1 = 0, ans2 = 0;
	for(int i = 0; i < x.size(); i++){
		ans1 = (ans1*p1%md1+x[i])%md1;
	}
	for(int i = 0; i < y.size(); i++){
		ans2 = (ans2*p2%md2+y[i])%md2;
	}
	return (ans1*md2%md1 + ans2)%md1;
}
unordered_map<int, vector<Node>> mp;
string a, b;
vector<int> cnt;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		int l = a.size(), r = 0;
		for(int j = 0; j < a.size(); j++){
			if(a[j] != b[j]){
				l = min(l, j);
				r = max(r, j);
			}
		}
		if(l > r) continue;
		string c = a.substr(l, r-l+1), d= b.substr(l, r-l+1);
		int hs = getHash(c, d);
		vector<Node> tmp;
		if(!mp.count(hs)){
			mp[hs] = tmp;
			cnt.push_back(hs);
		}
		mp[hs].push_back({l, a.size()-r-1});
	}
	for(int i = 0; i < cnt.size(); i++){
		sort(mp[cnt[i]].begin(), mp[cnt[i]].end(), cmp);
	}
	while(q--){
		cin >> a >> b;
		if(a.size() != b.size()){
			//cout << 0 << endl;
			continue;
		}
		int l = a.size(), r = 0;
		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i]){
				l = min(l, i);
				r = max(r, i);
			}
		}
		if(l > r) continue;
		string c = a.substr(l, r-l+1), d = b.substr(l, r-l+1);
		int hs = getHash(c, d), ll = l, rr = a.size()-r-1;
		if(!mp.count(hs)){
			cout << 0 << endl;
		}else{
			int ans = 0;
			vector<Node> tmp = mp[hs];
			for(int i = 0; i < tmp.size(); i++){
				if(tmp[i].x > ll){
					break;
				}
				if(tmp[i].y <= rr){
					ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
