#include<bits/stdc++.h>
#define ll long long
using namespace std; 
const int N=505,mod=998244353;	
ll n,m,c[N],a[N],ans,tot,vis[N];
string s;
void dfs(ll x){
	if(x==n){
		ll lst=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') {
				lst++;
				continue;
			}
			if(lst>=c[a[i]]) lst++;
			else cnt++;
		}
		if(cnt>=m) {
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[++tot]=i;
		dfs(x+1);
		tot--,vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	dfs(0);
	printf("%lld",ans);
	return 0;
}
