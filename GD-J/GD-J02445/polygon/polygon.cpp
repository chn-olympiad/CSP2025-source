#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v; 
int dfs(int sum , int longest , int num , int x){
	if(x >= v.size()) return 0;
	int myreturn = ((sum > (longest*2))&&num > 2);
	return (dfs(sum,longest,num,x+1) + dfs(sum+v[x],max(longest,v[x]),num+1,x+1) + myreturn)%998244353;
}
int dfs2(int sum , int longest , int num , int x){
	if(x >= v.size()) return ((sum > (longest*2))&&num > 2);
	int myreturn = ((sum > (longest*2))&&num > 2);
	return (dfs2(sum,longest,num,x+1) + dfs2(sum+v[x],max(longest,v[x]),num+1,x+1) + myreturn)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	int ans = dfs2(0,0,0,0) - dfs(0,0,0,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
