#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500+5,mod=998244353;
int vis[N],n,m,ans,fac[N],a[N];
string s;
void dfs(int now,int su,int fail){
	if(su==m) ans+=fac[n-su-fail-1];
	vis[now]=1;
	if(fail>=a[now]||s[su+fail]=='0'){
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				dfs(i,su,fail+1);
			}
		}
	}else{
		if(su+1==m) ans+=fac[n-su-fail-1];
		else{
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					dfs(i,su+1,fail);
				}
			}			
		}

	}
	vis[now]=0;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod; 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(i,0,0);
	}
	cout<<ans;
	return 0;
} 
