#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;

int n,m,c[25],ans;
string s;
bool vis[25];

void dfs(int cur,int sc,int fl){
	if(cur>n){
		if(sc>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(fl>=c[i]||s[cur-1]=='0'){
				vis[i]=1;
				dfs(cur+1,sc,fl+1);
				vis[i]=0;
			}else{
				vis[i]=1;
				dfs(cur+1,sc+1,fl);
				vis[i]=0;
			}
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	dfs(1,0,0);
	printf("%lld",ans);
	
	return 0;
}
