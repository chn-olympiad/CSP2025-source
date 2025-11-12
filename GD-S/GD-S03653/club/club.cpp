#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn = 1e5+2;
int t;

void dfs(int dep,int n1,int n2,int n3 , ll hap,int n,int* b1,int* b2,int *b3,ll& ans){
	if(dep > n){
		ans = max(ans , hap);
		return;
	}
	if(n1 + 1 <= (n/2)){
		dfs(dep+1,n1+1,n2,n3,hap + b1[dep],n,b1,b2,b3,ans);
	}
	if(n2 + 1 <= (n/2)){
		dfs(dep+1,n1,n2+1,n3,hap + b2[dep],n,b1,b2,b3,ans);
	}
	if(n3 + 1 <= (n/2)){
		dfs(dep+1,n1,n2,n3+1,hap + b3[dep],n,b1,b2,b3,ans);
	}
	
	return;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	
	while(t--){
		int n,b1[mn],b2[mn],b3[mn];
		ll ans = 0;
		bool vis[mn];
		memset(vis,0,sizeof(mn));
		
		cin >> n;
		
		for(int i = 1 ; i <= n ; i++){
			cin >> b1[i] >> b2[i] >> b3[i];
		}
		
		dfs(1,0,0,0,0,n,b1,b2,b3,ans);
		
		cout << ans << endl;
			
	}
	
	return 0;
} 
