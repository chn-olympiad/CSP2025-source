#include<bits/stdc++.h>
using namespace std;
const int N = 6e6 + 5;
int n,q,son[N][29],ls[N],val[N],tot;
int zh(char c){
	if (c == '!'){
		return 0;
	}
	if (c == '*'){
		return 1;
	}
	if (c == '#'){
		return 2;
	}
	return c - 'a' + 3;
}
string gx(string s,string t){
	if (s == t){
		return "!";
	}
	int lcp = 0,lcs = s.size() - 1;
	while (s[lcp] == t[lcp]){
		lcp++;
	}
	while (s[lcs] == t[lcs]){
		lcs--;
	}
	string rc = s.substr(lcs + 1,s.size() - lcs - 1);
	string lc = s.substr(0,lcp);
	string sm = s.substr(lcp,lcs + 1 - lcp);
	string tm = t.substr(lcp,lcs + 1 - lcp);
	return lc + "*" + sm + "#" + tm + "*" + rc;
}
void ACadd(string s){
	int p = 0;
	for (int i = 0;i < s.size();i++){
		int fn = zh(s[i]);
		(!son[p][fn]) && (son[p][fn] = ++tot);
		p = son[p][fn];
	}
	val[p]++;
}
void ACinit(){
	queue<int> q;
	for (int i = 0;i < 29;i++){
		if (son[0][i]){
		  ls[son[0][i]] = 0,q.push(son[0][i]);
	  }
	}
	while (!q.empty()){
		int x = q.front();
		q.pop();
		val[x] += val[ls[x]];
		for (int i =0;i < 29;i++){
			if (son[x][i]){
				ls[son[x][i]] = son[ls[x]][i];
				q.push(son[x][i]);
			}
			else{
				son[x][i] = son[ls[x]][i];
			}
		}
	}
}

int ACcx(string s){
	int p = 0,ans = 0;
	for (int i = 0;i < s.size();i++){
		int fn = zh(s[i]);
		p = son[p][fn];
		ans += val[p];
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> q;
  string s,t;
  for (int i = 1;i <= n;i++){
  	cin >> s>> t;
  	ACadd(gx(s,t));
	}
	ACinit();
	for (int i = 1;i <= q;i++){
		cin >> s >> t;
		if (s.size() != t.size()){
			cout << "0\n";
			continue;
		}
		cout << ACcx(gx(s,t)) << "\n";
	}
}
/*

*/
