// 陈健松 贵阳市第一中学 GZ-S00456

#include<bits/stdc++.h>
// 不开ll见祖宗 
using namespace std;
#define ll long long
#define in(var) ll var; cin >> var; 
#define repeat(var,from,to) for(ll var=from;var<to;var++)
#define repeati(var,from,to) for(int var=from;var<to;var++)
//tree<> t;
struct pth {
	ll first, second;
}; 
bool operator<(const pth& a, const pth& b){
	return a.second > b.second;
}
priority_queue<pth> w[10000 + 50]; 
priority_queue<pth> w2[10000 + 50]; 
ll citycost[10 + 1]; 
ll dic[10000+5][10000+5]; 
ll a[10 + 1][10 + 1]; 
int vis[10000 + 50];
int n,m,k;
vector<int> primTree;
ll prim(){
	 	primTree.clear();
		memset(vis, 0, sizeof(n));
		primTree.push_back(0);
		vis[0] = 1;
		ll ans = 0;
		
		while(primTree.size() < n){
			ll minPath = 1<<30;
			int newP = -1;
			int fromP = -1;
			int s;
			for(int p : primTree){
				while(!w[p].empty()){
					auto path = w[p].top();
					if(vis[path.first]) {
						w[p].pop();
						continue;
					}
					if(minPath > path.second){
						minPath = path.second;
						newP = path.first;
						fromP = p; 
					}
					break;
				}
			}
//			w2[fromP].push({newP, minPath});
//			w2[newP].push({fromP, minPath});
			
//			w2.push({newP, minPath});
			primTree.push_back(newP);
			vis[newP] = 1;
			ans += minPath;
		}
		return ans;
}
void solve(){
	memset(citycost, 0, sizeof(citycost));
	memset(a, 0, sizeof(a));
	repeat(a,0,10000+5)
		repeat(b,0,10000+5)
			dic[a][b] = 1LL<<50;
	cin >> n;
	cin >> m;
	cin >> k;
	repeat(i, 0, m){
		in(u)
		in(v)
		in(wi)
//		j += u + v + wi;
		w[u-1].push({v-1, wi});
		w[v-1].push({u-1, wi});
	}
	m += k; // ?
	repeat(i, 0, k){
		in(a1)
		citycost[i] = a1;
		repeat(j, 0, n){
			in(aj)
			a[i][j] = aj;
		}
		
//		repeat(i, 0, k){
//			ll a1 = citycost[i];
			repeati(b, 0, n){
				repeati(c, 0, n)
				{
					ll len = a[i][b] + a[i][c] + a1;
					dic[b][c] = min(len, dic[b][c]);
					dic[c][b] = min(len, dic[c][b]);
				}
			}
//		}
	}
			repeati(b, 0, n){
				repeati(c, 0, n)
				{
					ll len = dic[b][c];
//					cout <<len<<endl; 
					w[b].push({c, len});
					w[c].push({b, len});
				}
			}
	ll ans = prim();
	// 再来进行处理 
	cout << ans << endl; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	return 0;
}
