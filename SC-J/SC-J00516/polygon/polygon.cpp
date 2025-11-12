#include <bits/stdc++.h>
using namespace std;
vector<int> ij;
int max(int a, int b){
	if( a > b){
		return a;
		
	}
	return b;
}
int dfs_ans(int i, double prev_tot, int prev_max, int n, int prev){
	int ans = 0;
	if(prev_tot / 2> prev_max and prev >= 3){
//		cout<<prev_tot<<prev_max<<prev<<' ';
		ans++;
	}
	for(int j = i + 1; j < n; j++){
		ans += dfs_ans(j, prev_tot + ij[j], max(prev_max, ij[j]), n, prev+1);
	}
	return ans;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin>>n;
	ij.resize(n);
	for(int i = 0; i < n; i ++){
		cin>>ij[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i ++)
	ans += dfs_ans(i, ij[i], ij[i], n, 1);
	cout<<ans;
}