#include<bits/stdc++.h>
using namespace std;
#define int long long
const int kMaxN = 100005;
int a[kMaxN][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,ans = 0;
		cin >> n;
		vector<int> v[3];
		for(int i = 1;i <= n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int maxn = max(a[i][0],max(a[i][1],a[i][2]));
			ans += maxn;
			for(int j = 0;j <= 2;j++){
				if(a[i][j] == maxn){
					v[j].push_back(i);
					break;
				}
			}
			//cout << i << ":" << maxn << "\n";
		}
		int p= -1;
		for(int i = 0;i <= 2;i++){
			if(v[i].size() > n/2){
				p = i;
			}
		}
		if(p == -1){
			cout << ans << '\n';
		}else{
			vector<int> vv;
			for(int i = 0;i < v[p].size();i++){
				int maxn = -1e9;
				for(int j = 0;j <= 2;j++){
					if(j!=p){
						maxn = max(maxn,a[v[p][i]][j]-a[v[p][i]][p] );
					}
				}
				vv.push_back(maxn);
			}
			sort(vv.begin(),vv.end());
			reverse(vv.begin(),vv.end());
			int siz = v[p].size();
			for(int i = 0;i < siz - n/2;i++){
				ans  += vv[i];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
