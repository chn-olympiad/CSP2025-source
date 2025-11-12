#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 200005;
int n, q, lx, ly;
pair<string, string> s[N];

void sol() {
	long long ans = 0;
	string x, y, xx;
	cin>>x>>y;
	lx = x.length();
	ly = y.length();
	for(int i=1, fx, fy; i<=n; i++) {
		fx = x.find(s[i].fi);
		fy = y.find(s[i].se);
		if(fx==-1 || fy==-1) continue;
//		cout<<fx<<' '<<fy<<endl;
		xx = x;
		for(int j=0; j<(int)s[i].se.length(); j++)
			xx[j+fx] = s[i].se[j];
		if(xx == y) {
//			cout<<xx<<endl;
			++ans;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++)
		cin>>s[i].fi>>s[i].se;
	while(q--) sol();
	return 0;
}
