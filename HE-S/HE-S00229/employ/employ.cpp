#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
string s;
int a[N], p[N];
int ans;
bool st[N];

void dfs(int u){
	if(u > n){
		int q = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(s[i] == '0' || q >= a[p[i]]) q ++;
		}
		if(n - q >= m) ans ++;
		return ;
	}
	
	for(int i = 1 ; i <= n ; i ++){
		if(st[i]) continue;
		st[i] = true;
		p[u] = i;
		dfs(u + 1);
		p[u] = 0;
		st[i] = false;
	}
}

int main(){
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin>>n>>m>>s;
	s = ' ' + s;
	for(int i = 1 ; i <= n ; i ++){
		cin>>a[i];
	}
	
	dfs(1);
	
	cout<<ans;
	/* 
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
	return 0;
}
