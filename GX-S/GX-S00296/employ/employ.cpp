#include <bits/stdc++.h>
using namespace std;
const int N = 500;
struct node{
	int c , id;
}em[N];
int n , m , res;
vector<int> pm;
bool vis[N];
string s;
void check(){
	int c1 = 0 , c2 = 0 , sum = n;
	for(size_t i = 0 ; i < pm.size() ; ++i){
		if(c2 >= em[pm[i]].c) sum--;
		if(s[i] == '1') c1++;
		else c2++ , sum--;
		
	}
	if(sum >= m) res++;
	res = res % 998244353;
	return;
}
void dfs(int dep){
	if(dep == n + 1){
		check();
		return;
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!vis[i]){
			vis[i] = true;
			pm.push_back(i);
			dfs(dep + 1);
			pm.pop_back();
			vis[i] = false;
		}
	}
}

int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1 ; i <= n ; ++i){
		cin >> em[i].c;
		em[i].id = i;
	}
	dfs(1);
	cout << res;
	return 0;
}
