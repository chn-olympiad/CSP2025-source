# include <iostream>
# include <cstring>
# include <map>
# define FILE
//# define mulq
using namespace std;
pair<string,string> to[200005];
void solve(){
	int n,q; cin >> n >> q;
	for (int i = 1;i <= n;i++){
		string u,v; cin >> u >> v;
		to[i] = {u,v};
	}while (q--){
		string s,t; cin >> s >> t;
		int cnt = 0;
		for (int i = 1;i <= n;i++){
			string cur = s;
			if (cur.find(to[i].first) != string::npos){
				cur = cur.substr(0,cur.find(to[i].first)) + to[i].second + cur.substr(cur.find(to[i].first) + to[i].first.size(),cur.size());
				if (cur == t) cnt++;
			}
		}cout << cnt << endl;
	}
}int main(){
	# ifdef FILE
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	# endif
	# ifdef mulq
	int q; cin >> q;
	while (q--) solve();
	# else
	solve();
	# endif
	return 0;
}
