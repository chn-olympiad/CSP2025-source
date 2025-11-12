#include<bits/stdc++.h>
#define debug 0
const int N = 500;
const int mod = 998244353;
//debug 1 -> start debug
using namespace std;
int a[N];
bool vis[N];
int n,m,ans;
string str;
void dfs(int level,int x,int p){
	if(level == n){
		if(p >= m - 1)ans++;
		ans = ans % mod;
		return;
	}
	vis[x] = 1;
	for(int i = 1;i<= n;i++){
		if(vis[i])continue;
		if(str[level] == '1' && level - p + 1 <= a[i]){
			dfs(level + 1,i,p + 1);
		}
		else dfs(level + 1,i,p);
		//cout << p;
	}
	vis[x] = 0;
}
void the_main(){
	cin >> n >> m;
	cin >> str;
	str = "s" + str;
	for(int i = 1;i<= n;i++)cin >> a[i];
	for(int i = 1;i<= n;i++){
		dfs(1,i,0);
	}
	cout << ans;
}

int main(){
	#if debug == 1
	cout << "start debug";
	#else
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif
	the_main();
	#if debug != 1
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}
