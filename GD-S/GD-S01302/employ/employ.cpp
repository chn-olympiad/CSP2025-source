#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e2 + 15;
ll ans;
int n,m,a[N];
bool viss[N],vis[N];
void dfs(int x,int y,int z,int len){
	if(z >= m && len == 0){
		ans ++;
		return ;
	}
	if(len == 0){
		return ;
	}
	for(int i = 1;i <= n;i ++){
		if(vis[i]){
			continue;
		}
		vis[i] = 1;
		if(!viss[n - len + 1]){
			dfs(i,y + 1,z,len - 1);
		}else{
			if(y >= a[i]){
				dfs(i,y + 1,z,len - 1);
			}else{
				dfs(i,y,z + 1,len - 1);
			}
		}
		vis[i] = 0;
	}
	return ;
}
int main(){
//	freopen("employ2.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		char c;
		cin >> c;
		viss[i] = (int)(c - '0');
	}
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	dfs(0,0,0,n);
	cout << ans;
	return 0;
} 
