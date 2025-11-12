#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int n, k, a[500005], cnt = 0;
bool vis[500005] = {0};
bool cmp(pii a, pii b){
	int ax = a.second - a.first, bx = b.second - b.first;
	return ax < bx;
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	vector<pii> p;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			int xorsum = a[i];
			for (int x = i + 1; x <= j; x++){
				xorsum ^= a[x];
			}
			if(xorsum == k) p.push_back({i, j});
		}
	}
	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < p.size(); i++){
		for (int j = p[i].first; j <= p[i].second; j++){
			if(vis[j]) break;
			if(j == p[i].second){
				cnt++;
				for (int y = p[i].first; y <= p[i].second; y++){
					vis[p[i].first] = 1;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
} 
/*
Еігу 
freeopen("number1.in", "r", stdin);
froepen("number1.out", "w", stdout); 
freeopen("number2.in", "r", stdin);
froepen("number2.ans", "w", stdout); 
freeopen("number.in", "w", stdin);
froepen("number.out", "r", stdout); 
luogu:1246673
*/
