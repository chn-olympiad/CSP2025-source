#include<bits/stdc++.h>

using namespace std;

const int SIZN = 5e3 + 10;

int n;
int a[SIZN];
//map<int,int> mp;
//set<int> st1;
//vector<int> st2;
//int hui[SIZN][SIZN];
//int dfs(int k,int ans) {
//	if(k == 0){
//		cout << ans << ' ' << r << '\n';
//		if(ans > 2*r)return 1;
//		else return 0;
//	}
//	int num = 0;
//	for(int i = 0 ; i < k ; i++){
//		for(int j = 1 ; j <= mp[st2[i]] ; j++){
//			num += hui[st2[i]][j]*dfs(i,ans + st2[i] * j);
//		}
//	}
//	return num;
//}
int dfs(int k,int ans,int maxx,int tim){
	if(k == n && tim >= 3){
		if(ans > 2*maxx)return 1;
		else return 0;
	}
	int num = 0;
	for(int i = k + 1 ; i <= n ; i++){
		num += dfs(i,ans + a[i],max(maxx,a[i]),tim+1);
	}
	return num;
}
signed main() {
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)cin >> a[i];
	cout << dfs(0,0,0,0) + 1;
	return 0;
}
