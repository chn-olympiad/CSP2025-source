#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pair;
vector<int> W;
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		W.push_back(w);
	}
	sort(W.begin() , W.end());
	for(int i = 1;i <= k;i++)
	{
		int p;
		cin >> p;
		for(int i = 1;i <= n;i++)
		{
			int w;
			cin >> w;
		}
	}
	ll ans = 0;
	for(int i = 1;i < n;i++)
	{
		ans += W[i];
	}
	cout << ans;
	return 0;
}

