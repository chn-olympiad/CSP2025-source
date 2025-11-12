
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,qq;
string s;
int n,cnt,m,k;
int ans;
int mn[N],h[N];
int dis[N];
int aa,bb,cc;struct node {
	int u,v,w;
};
vector<node> e;
queue<int> q;
bool inp[N];

void solve() {
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=m;i++){
		cin>>t;
	}
	cout<<rand();
}

signed main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	return 0;
}


/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/



