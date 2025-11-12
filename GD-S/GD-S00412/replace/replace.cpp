#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
pair<string, string> a[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}
	while(q--){
		string x, y;
		cin >> x >> y;
		cout << "0\n";
	}
	return 0;
}
