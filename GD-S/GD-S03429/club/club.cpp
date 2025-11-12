#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int p[N][5];
vector<int> vec[5];
int n,T;
void solve(){
	cin >> n;
	int ans = 0; 
	for(int i = 1;i <= n;i++){
		cin >> p[i][1] >> p[i][2] >> p[i][3];
		int maxx = max(p[i][1],max(p[i][2],p[i][3]));
		int midv = p[i][1] + p[i][2] + p[i][3] - maxx - min(p[i][1],min(p[i][2],p[i][3]));
		int idmax = 0;
		for(int j = 1;j <= 3;j++){
			if(maxx == p[i][j])
				idmax = j;
		}
		int dif = p[i][idmax] - midv;
//		cout << dif[i] << " " << idmax <<" " << idmin << '\n';
		ans += p[i][idmax];
		vec[idmax].push_back(dif);
	}
	if(vec[1].size() <= n / 2 && vec[2].size() <= n / 2 && vec[3].size() <= n / 2){
		cout << ans << '\n';
	
	}
	else{
		int id = 0;
		if(vec[1].size() > n / 2) id = 1;
		else if(vec[2].size() > n / 2) id = 2;
		else id = 3;
		sort(vec[id].begin(),vec[id].end());
		for(int i = 0;i < vec[id].size() - n / 2;i++){
			ans -= vec[id][i];
		}
		cout << ans <<'\n';
	}  
	vec[1].clear(); vec[2].clear(); vec[3].clear();
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
		solve();
	return 0;
}
