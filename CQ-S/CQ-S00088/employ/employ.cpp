#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,mod=998244353;
ll n,m,c[N],ans=0;
char h[N];
ll vis[N];
void dfs(ll now,ll cnt,ll k){
	if(now>n){
		if(k>=m){
			ans++;
			if(ans>mod) ans-=mod;
		}
		return;
	}
//	ll tmp=cnt;
//	for(int i=1;i<=n;i++){
//		if(!vis[i]&&c[i]<=tmp) tmp++;
//		else break;
//	}
//	cout<<tmp<<"\n";
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(h[now]=='0'||c[i]<=cnt) dfs(now+1,cnt+1,k);
		else dfs(now+1,cnt,k+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
