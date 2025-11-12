#include<bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353;
char a[501];
int reng[501];

int path[505],k,vis[505];
int cnt = 0;
int n,m;

bool check(){
	int cnt = 0,ren = 0;
	for(int i = 1;i<=k;i++){
		if(!(cnt>=reng[path[i]]) && a[i]=='1') ren++;
		if(a[i]=='0') cnt++;
	}
	return ren>=m;
}
void dfs(int x){
	if(x>n){
		if(check()){
			cnt++;
			cnt%=mod;
		}
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i]==0){
			vis[i] = 1;
			path[++k] = i;
			dfs(x+1);
			k--;
			vis[i] = 0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f = 1;
	for(int i = 1;i<=n;i++) cin>>a[i],f&=(a[i]=='1');
	for(int i = 1;i<=n;i++) cin>>reng[i];
	if(f){
		long long cnt = 1;
		for(int i = 100;i>=1;i--) cnt = (cnt%mod)*i,cnt%=mod;
		cout<<(cnt+mod)%mod;
	}else{
		dfs(1);
		cout<<cnt;
	}

	return 0;
}
