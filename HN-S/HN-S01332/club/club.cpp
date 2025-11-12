#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5 + 5;
int n,a[N][3],ans;
vector<int> va[3];
void solve(){
  cin >> n;
  for (int i = 0;i < 3;i++){
  	va[i].clear();
	}
	ans = 0;
  for (int i = 1;i <= n;i++){
  	cin >> a[i][0] >> a[i][1] >> a[i][2];
  	if ((a[i][0] >= a[i][1]) && (a[i][0] >= a[i][2])){
  		ans += a[i][0];
  		va[0].push_back(max(a[i][1],a[i][2]) - a[i][0]);
		}
		if ((a[i][1] > a[i][0]) && (a[i][1] >= a[i][2])){
			ans += a[i][1];
			va[1].push_back(max(a[i][0],a[i][2]) - a[i][1]);
		}
		if ((a[i][2] > a[i][1]) && (a[i][2] > a[i][0])){
			ans += a[i][2];
			va[2].push_back(max(a[i][0],a[i][1]) - a[i][2]);
		}
	}
	for (int i = 0;i < 3;i++){
		if (va[i].size() > n / 2){
			sort(va[i].begin(),va[i].end());
			while (va[i].size() > n / 2){
				ans += va[i].back();
				va[i].pop_back();
			}
		}
	}
	cout<< ans << "\n";
}
signed main(){
	
	freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  for (cin >> t;t--;){
  	solve();
	}
}
