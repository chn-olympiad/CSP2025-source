#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

const int N = 2e5 + 10;
int n, q; string s[N][2], t1, t2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		cin >> t1 >> t2; int cnt = 0;
		if(n*q > 1e4){
			cout << 0 << '\n';
			continue;
		} 
		for(int i = 1; i <= n; i++){
			if(s[i][0].size() > t1.size()) continue;
			for(int j = 0; j <= t1.size()-s[i][0].size(); j++){
				if(t1.substr(0, j) + s[i][0] + t1.substr(j+s[i][0].size()) == t1 && t1.substr(0, j) + s[i][1] + t1.substr(j+s[i][0].size()) == t2){
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
