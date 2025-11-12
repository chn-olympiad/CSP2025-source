# include <algorithm>
# include <iostream>
# include <vector>
# include <queue>
# include <map>
# define FILE
# define mulq
using namespace std;
int n,a[100005][8],b[100005];
priority_queue<pair<int,pair<int,int>>> bm[8];
void put(int id,int pck){
	int pos = a[id][pck];
	if (pck == 3){
		if (bm[pos].size() == (n >> 1)){
			queue<pair<int,pair<int,int>>> q;
			while (!bm[pos].empty()){
				pair<int,pair<int,int>> f = bm[pos].top();
				bm[pos].pop();
				if (f.second.second == 3) q.push(f);
				else{
					put(f.second.first,f.second.second + 1);
					break;
				}
			}bm[pos].push({a[id][pck],{id,pck}});
			while (!q.empty()) bm[pos].push(q.front()),q.pop();
		}else bm[pos].push({a[id][pck],{id,pck}});
	}if (bm[pos].size() == (n >> 1)) put(id,pck + 1);
	else bm[pos].push({a[id][pck],{id,pck}});
}void solve(){
	cin >> n;
	bool sp_a = 1;
	for (int i = 1;i <= n;i++){
		cin >> a[i][4] >> a[i][5] >> a[i][6];
		int Mx = max(a[i][4],max(a[i][5],a[i][6]));
		if (a[i][4] == Mx) a[i][1] = 1;
		else if (a[i][5] == Mx) a[i][1] = 2;
		else a[i][1] = 3;
		int Mn = min(a[i][4],min(a[i][5],a[i][6]));
		if (a[i][4] == Mn && a[i][1] != 1) a[i][3] = 1;
		else if (a[i][5] == Mn && a[i][1] != 2) a[i][3] = 2;
		else a[i][3] = 3;
		if (a[i][1] != 1 && a[i][3] != 1) a[i][2] = 1;
		else if (a[i][1] != 2 && a[i][3] != 2) a[i][2] = 2;
		else a[i][2] = 3;
		
		int ttmmpp = (a[i][4] == 0) + (a[i][5] == 0) + (a[i][6] == 0);
		if (ttmmpp < 2) sp_a = 0;
		
		
	}if (sp_a){
		for (int i = 1;i <= n;i++) b[i] = a[i][1];
		sort(b + 1,b + n + 1,[](int x,int y){ return x > y; });
		int ans = 0;
		for (int i = 1;i <= (n << 1);i++) ans += b[i];
		cout << ans << endl;
		return;
	}for (int i = 1;i <= n;i++) put(i,1);
	int ans = 0;
	for (int i = 1;i <= 3;i++){
		while (!bm[i].empty()){
			auto f = bm[i].top(); bm[i].pop();
			ans += f.first;
		}
	}cout << ans << endl;
}int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	# ifdef FILE
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	# endif
	# ifdef mulq
	int q; cin >> q;
	while (q--) solve();
	# else
	solve();
	# endif
	return 0;
}
