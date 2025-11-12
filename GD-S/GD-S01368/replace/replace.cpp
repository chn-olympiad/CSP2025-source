#include<bits/stdc++.h>
using namespace std;

string s[200005], ss[200005];
int n, q;

int main(){
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i=1; i<=n; i++) cin >> s[i] >> ss[i];
	for(int i=1; i<=q; i++){
		string str, as;
		cin >> str >> as;
		long long sum = 0;
		for(int i=1; i<=n; i++){
			int t = str.find(s[i]);
			if(t < str.size()){
				string sss = str.substr(0, t) + ss[i] + str.substr(t+s[i].size());
				if(sss == as)sum++;
			}
		}
		cout << sum <<  "\n";
	}
	return 0;
}
