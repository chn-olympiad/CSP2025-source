#include <iostream>
#include <vector>
#include <map>
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define ll long long 
#define rop(i, j, k) for(int i = j; i >= k; i--)
#define big __int128
#define ull unsigned ll 
using namespace std;
const int N = 2e5 + 5;
map<string, vector<string> > mp;
int a[N], n, q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	rep(i, 1, n){
		string x, y;
		cin >> x >> y;
		mp[x].push_back(y);
	} 
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		int r = t1.size(), res = 0;
		rep(i, -1, r - 1){
			rop(j, r, 0){
				string x, y, z;
				x = y = z = "";
				if(i != -1) rep(k, 0, i) x += t1[k];
				rep(k, i + 1, j - 1) y += t1[k];
				if(!mp[y].size()) continue;
				if(j != r) rep(k, j, r - 1) z += t1[k];
				rep(k, 0, mp[y].size() - 1){
					string ny = mp[y][k], now = x + ny + z;
					if(now == t2) res++;
				} 
			}
		}
		cout << res << "\n";
	}
	return 0;	
} 
