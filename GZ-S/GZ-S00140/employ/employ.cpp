//GZ-S00140 贵州省织金育才学校 宋载航 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e5+9,M=1e6+9,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll T=1;
ll n,m,c[N],vis[N],ans,jc[N];
string s;
void dfs(ll now,ll sum){
	if(m-sum>n-now+1){
		return ;
	}
	if(sum==m){
		ans=(ans+jc[n-now])%mod;
		return ;
	}
	if(now==n){
		return ;
	}
	if(s[now]=='0'){
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				dfs(now+1,sum);
				vis[i]=0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(now-sum<c[i]){
					vis[i]=1;
					dfs(now+1,sum+1);
					vis[i]=0;
				}
				else{
					vis[i]=1;
					dfs(now+1,sum);
					vis[i]=0;
				}
			}
		}
	}
}
inline void solve(){
	cin>>n>>m;
	cin>>s;
	jc[0]=1;
	bool lf=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			lf=1;
		}
		jc[i]=(jc[i-1]*i)%mod;
	}
	bool fl=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			fl=0;
		}
	}
	if(m==n){
		if(fl==0||lf==1){
			cout<<0;
		} 
		else{
			cout<<jc[n];
		}
		return ;
	}
	if(n<=18){
		sort(c+1,c+n+1);
		dfs(0,0);
		cout<<ans;
		return ;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
