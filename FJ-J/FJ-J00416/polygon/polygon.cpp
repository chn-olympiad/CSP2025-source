#include<bits/stdc++.h>
using namespace std;
bool vis[5005], vi[300000];
int n, a[5005];
int cnt = 0;
void dfs(int e,int x, int mx){
	if(x > mx*2){
		if(vi[x] == 0){
			cnt++;
			vi[x] = 1;
		}
	}
	if(e > n){
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(e+1,x+a[i], max(mx, a[i]));
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int e = INT_MIN;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		e = max(e, a[i]);
	}
	if(e == 1){
		cout << 2*n+2;
		return 0;
	}
	dfs(1,0,INT_MIN);
	cout << cnt;
	return 0;
}
