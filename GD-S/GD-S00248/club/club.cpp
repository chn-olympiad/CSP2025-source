#include<iostream>
using namespace std;
int t,n,maxn;
const int N = 100000;
int a[N][3];
int v[3];
int ans[6];
void dfs(int x,int y){
	if(x > n){
		maxn = max(maxn,y);
		return;
	}
	for(int i = 1; i <= 3; i++){
		if(v[i] < n/2){
			v[i]++;
			dfs(x+1,y+a[x][i]);
			v[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= 3; k++){
				cin >> a[j][k];
			}
		}
		dfs(0,0);
		ans[i] = maxn;
		maxn = 0;
	}
	for(int i = 1; i <= t; i++){
		cout << ans[i] << endl;
	}
	return 0;
} 
