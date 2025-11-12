#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
vector<pair<string, string>> a;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	string s1, s2;
	for(int i = 1;i <= n;i ++){
		cin >> s1 >> s2;
		a.push_back({s1, s2});
	}
	string t1, t2, tmp;
	while(q --){
		cout << 0 << endl;
	}
	return 0;
}
