#include<bits/stdc++.h>
using namespace std;
int s[505],c[505];int n,m;
int sele[505],vis[505], ans;
void dfs(int deep){
	if(n<deep){
		int giv=0;
		for(int i=1;i<=n;i++){
			if(giv>=c[sele[i]]){
				giv++;
			}else{
				giv+=!s[i];
			}
		}if(n-giv>=m)ans=(ans+1)%998244353;
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				sele[deep]=i;
				dfs(deep+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	string r;cin >> r;
	int x=0;
	for(int i=1;i<=n;i++){
		s[i]=(r[i-1]-'0');
	}for(int i=1;i<=n;i++){
		cin >> c[i];
	}
		dfs(1);
		cout << ans;
	
} 
