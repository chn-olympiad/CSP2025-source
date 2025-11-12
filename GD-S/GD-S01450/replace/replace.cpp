#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q;
string x, y;
vector<string> s1;
vector<string> s2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(ll i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;
		s1.push_back(a);
		s2.push_back(b);
	}
	for(ll q_i = 0;q_i < q; q_i++){
		ll ans = 0;
		cin >> x >> y;
		for(ll k = 0; k < n; k++){
			ll m = s1[k].size();
			string tmp_s1 = s1[k];
			for(ll i = 0; i < x.size(); i++){
				bool op = true;
				ll res = i;
				for(ll j = 0; j < m; j++, i++){
					if(tmp_s1[j] != x[i]){
						op = false;
						break;
					}
				}
				i = res;
				if(op == true && x.substr(0, i)+s2[k]+x.substr(i+m, x.size()-i-m) == y){
					ans++;
				}
			}
		}
		cout << ans <<endl;
	}
	return 0;
}
