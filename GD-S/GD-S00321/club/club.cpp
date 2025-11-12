#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, p[N][4], max_;

void dfs(int x, int cnt1, int cnt2, int cnt3, int v){
	if(x>n){
		max_ = max(max_, v);
		return;
	}
	if(cnt1<n/2)
		dfs(x+1, cnt1+1, cnt2, cnt3, v+p[x][1]);
	if(cnt2<n/2)
		dfs(x+1, cnt1, cnt2+1, cnt3, v+p[x][2]);
	if(cnt3<n/2)
		dfs(x+1, cnt1, cnt2, cnt3+1, v+p[x][3]);
	return;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		max_ = 0;
		for(int i=1;i<=n;++i){
			cin >> p[i][1] >> p[i][2] >> p[i][3];
		}
		dfs(1, 0, 0, 0, 0);
		cout << max_ << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
