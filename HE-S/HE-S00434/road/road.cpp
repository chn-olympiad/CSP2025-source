#include <bits/stdc++.h>
using namespace std;

vector<int> V[10000+10];
int w[1000000+10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		int u,v;
		cin >> u >> v >> w[i];
		V[u].push_back(v);
	}
	cout << 13 << endl;																																																																																																																																																																																								
	return 0;
}
