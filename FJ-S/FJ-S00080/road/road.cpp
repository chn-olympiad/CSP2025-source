#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int t[1005][1005];
int vis[1005];
vector <int> v[1005];
long long ans = 1e9+5;
bool in(){
	for(int i = 1; i <= n ;i++){
		if(vis[i] == 0) return 0;
	}
	return 1;
}
long long sum;
void f(int x){
	cout << x <<endl;
	for(int i = 1 ;i <= n ;i++){
		cout << vis[i] <<' ';
	}
	cout << endl;
	if(in()){
		ans = min(ans, sum);
	}
	
	for(int i = 0 ;i < v[x].size(); i++){
		if(vis[v[x][i]] == 0){
			vis[v[x][i]] = 1;
			sum += t[x][v[x][i]];
			cout << sum << endl;
			f(v[x][i]);
			sum -= t[x][v[x][i]];
			vis[v[x][i]] = 0;
		}
		

	}
	
	
	
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m ;i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[b].push_back(a);
		t[a][b] = c;
	}
	vis[1] = 1;
	f(1);
	cout << ans;
	
	
	return 0;
}
