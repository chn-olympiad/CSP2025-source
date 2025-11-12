#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using LL = long long;

int n, T, a[N][3], maxn = -1;

void dfs(int j, int w, int al, int bl, int cl){
	if(j == n + 1 && al <= n / 2 && bl <= n / 2 && cl <= n / 2){
		maxn = max(w, maxn);
		return ;
	}
	
	if(al > n / 2) return ;
	if(bl > n / 2) return ;
	if(cl > n / 2) return ;
	
	dfs(j + 1, w + a[j][0], al + 1, bl, cl);
	dfs(j + 1, w + a[j][1], al, bl + 1, cl);
	dfs(j + 1, w + a[j][2], al, bl, cl + 1);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		
		maxn = -1;
		dfs(1, 0, 0, 0, 0);
		
		cout << maxn << "\n";
	}
	return 0;
}
