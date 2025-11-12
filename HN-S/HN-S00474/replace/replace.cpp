#include<bits/stdc++.h>
using namespace std;



inline int read(){
	int x=0;char s=getchar();
	while(!isdigit(s)) s=getchar();
	while(isdigit(s)) x=(x<<1)+(x<<3)-'0'+s,s=getchar();
	return x;
}

void solve(){
	int n = read(), q =read();
	if(q == 1){
		
	}
	const int py = 5e6;
	map<int, vector<pair<int, int> > > qq;
	for(int i=1;i<=n;i++){
		string a, b;
		cin >> a >> b;
		int x = a.find("b"), y = b.find("b");
		qq[y - x + py].push_back({x, a.size() - x});
	}
	for(int i=1;i<=q;i++){
		int ans = 0;
		string a, b;
		cin >> a >> b;
		if(a.size() != b.size()){
			printf("0\n");
		}
		int x = a.find("b"), y = b.find("b");
		for(auto tt : qq[y - x + py]){
			int xx = tt.first;
			int yy = tt.second;
			if(x >= xx && a.size() - x >= yy){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T = 1;

	while(T--){
		solve();
	}
	return 0;
}

