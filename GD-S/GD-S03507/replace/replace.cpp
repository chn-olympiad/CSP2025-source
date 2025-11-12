#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n, q;
string s[200005], s2[200005];
string t, t2;
bool b[5000005], c[5000005];
bool f = true;
map<int, vector<pair<pair<int, int>, int>>> mp;

bool check(string s){
	int len = s.length() - 1;
	int cntb = 0;
	for(int i = 1; i <= len; i++){
		if(s[i] == 'b') cntb++;
		else if(s[i] != 'a') return false;
	} 
	return cntb == 1;
}

vector<int> find(string s, string t){
	vector<int> res;
	int lens = s.length() - 1, lent = t.length() - 1;
	for(int i = 1; i + lent - 1 <= lens; i++){
		bool ok = true;
		for(int j = 0; j < lent && ok; j++){
			if(s[i + j] != t[j + 1]){
				ok = false;
			} 
		}
		if(ok){
			res.push_back(i);
		}
	}	
	return res;
}

void work1(){
	int x = 0, y = 0;
	int lent = t.length() - 1;
	for(int i = 1; i <= lent; i++){
		if(t[i] == 'b') x = i;
		if(t2[i] == 'b') y = i;
	}	
	int ans = 0;
	for(auto i : mp[x - y]){
		int u = i.first.first, v = i.first.second;
		int w = i.second;
		if(u > x || x - u + w > lent) continue;
		if(v > y || y - v + w > lent) continue;
		ans++;
	}
	printf("%d\n", ans);
}

void work2(){
	b[0] = true;
	int lent = t.length() - 1;
	for(int i = 1; i <= lent; i++){
		b[i] = b[i - 1] & (t[i] == t2[i]);
	}
	c[lent + 1] = true;
	for(int i = lent; i >= 1; i--){
		c[i] = c[i + 1] & (t[i] == t2[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		vector<int> v = find(t, s[i]);
		int lens = s[i].length() - 1;
		for(auto x : v){
			bool flag = true;
			for(int j = 0; j < lens && flag; j++){
				if(s2[i][j + 1] != t2[x + j]){
					flag = false;
				}
			}
			if(flag){
				if(b[x - 1] && c[x + lens]){
					ans++; 
				}
			}
		}
	}
	printf("%d\n", ans);
} 

void solve(){
	cin >> t >> t2;
	int lent = t.length(), lent2 = t2.length();
	t = '#' + t, t2 = '#' + t2;
	if(!check(t)) f = false;
	if(!check(t2)) f = false;
	if(lent != lent2){
		cout << 0 << endl;
		return;
	}
	if(f) work1();
	else work2();
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> s2[i];
		s[i] = '#' + s[i];
		s2[i] = '#' + s2[i];
		if(!check(s[i])) f = false;
		if(!check(s2[i])) f = false;
	}
	if(f){
		for(int i = 1; i <= n; i++){
			int x = 0, y = 0;
			int lens = s[i].length() - 1;
			for(int j = 1; j <= lens; j++){
				if(s[i][j] == 'b') x = j;
				if(s2[i][j] == 'b') y = j;
			}
			mp[x - y].push_back({{x, y}, lens});
		}
	}
	while(q--) solve();
	return 0;
}
