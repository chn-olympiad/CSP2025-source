#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,c[N],num,ans,a[N];
string s;
bool vis[N];
inline void dfs(int x){
	if(x>n){
		int num=0;
		for(int i=1;i<=n;i++) if(num>=c[a[i]]||s[i-1]=='0') num++;
		if(n-num>=m) ans=(ans+1)%mod;
		return; 
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
} 
