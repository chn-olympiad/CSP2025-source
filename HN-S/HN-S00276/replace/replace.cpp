#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NR = 2e5 + 5;
int n,q;
string s[NR];
string t[NR];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s[i] >> t[i];
	while(q--){
		string x,y;
		cin >> x >> y;
		if(x.size() != y.size()){
			cout << "0\n";
			continue;
		}
		x = " " + x;
		y = " " + y;
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			int last = 1;
			while(x.find(s[i],last) != string::npos){
				string tmp = x;
				tmp.replace(x.find(s[i],last),s[i].size(),t[i]);
				if(tmp == y) cnt++;
				last = x.find(s[i],last) + 1;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}

