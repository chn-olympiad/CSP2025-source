#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, maxn, res = 0;
vector <vector <int> > a(MAX, vector <int> (4));
void dfs(int ii, vector <int> p, int ans){
	if(ii > n){
		res = max(res, ans);
		return ;
	}
	for(int i = 1; i <= 3; i++){
		if(p[i] < maxn){
			p[i]++;
			dfs(ii + 1, p, ans + a[ii][i]);
			p[i]--;
		}
	}
	return ;
}
void sol(){
	res = 0;
	scanf("%d", &n);
	maxn = n / 2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			scanf("%d", &a[i][j]);
		}
	}
	vector <int> p(4, 0);
	dfs(1, p, 0);
	printf("%d\n", res);
	return ;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) sol();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
