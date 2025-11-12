#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node {
	int a,b,c;
}adj[100005];
int n,ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> adj[i].a >> adj[i].b >> adj[i].c;
			ans+=max(max(adj[i].a,adj[i].b),adj[i].c);
		}
		cout << ans << endl;
	}
	return 0;
}
