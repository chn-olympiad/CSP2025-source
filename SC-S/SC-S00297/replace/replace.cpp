#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>

// How do I solve it, Takanashi Hoshino?
using namespace std;
const int MAX_N = 2e5+20;
int n, q;
string s1[MAX_N], s2[MAX_N], t1, t2;
vector<int> fs[MAX_N];

vector<int> getFail(const string &s){
	int len = s.length();
	vector<int> f(len+1);
	f[1] = f[0] = 0;
	for(int i=1;i<len;++i){
		int j = f[i];
		while(j && s[i]!=s[j])j = f[j];
		f[i+1] = s[i]==s[j]?j+1:0;
	}
	return f;
}

vector<int> match(const string &t, const string &p, const vector<int> f){
	vector<int> res;
	int len = t.length();
	int j=0;
	for(int i=0;i<len;++i){
		while(j && t[i]!=p[j])j = f[j];
		if(t[i]==p[j])++j;
		if(j==p.length())res.emplace_back(i);
	}
	return res;
}

void solve(const string &t1, const string &t2){
	int ans = 0, len = t1.length(), mn = len, mx = 0;
	for(int i=0;i<len;++i)if(t1[i]!=t2[i]){
		mn = i; break;
	}
	for(int i=len-1;i>=0;--i)if(t1[i]!=t2[i]){
		mx = i; break;
	}
	
	for(int i=1;i<=n;++i)if(s1[i].length()>=(mx-mn+1))
	for(int p:match(t1,s1[i], fs[i])){
		int plen = s1[i].length();
		if(p-plen+1<=mn && p>= mx){		
			bool ok=1;
			for(int j=0;j<plen;++j){
				if(t2[p-j]!=s2[i][plen-j-1]){
					ok=0;
					break;
				}
			}
			ans += ok;
		}
	}
	cout << ans << endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i=1;i<=n;++i){
		cin >> s1[i] >> s2[i];
		fs[i] = move(getFail(s1[i]));
	}
	for(int i=1;i<=q;++i){
		cin >> t1 >> t2;
		solve(t1, t2);
	}
	
}
