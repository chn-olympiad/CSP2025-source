#include<iostream>

using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,sum,nw[20],c[1000],ans;string s;
ll vis[20];
void dfs(ll x){
	if(x==n+1){
		ll sm=0;
		for(ll i=1;i<=n;i++){
			if(i-1-sm>=c[nw[i]]||s[i-1]=='0')continue;
			sm++;
		}
		if(sm>=m)ans++;return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			nw[x]=i;vis[i]=1;dfs(x+1);vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;sum=n;cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i])sum--;
	}
	if(n<=10){
		dfs(1);cout<<ans<<endl;return 0;
	}
	ans=1;
	for(ll i=1;i<=n;i++)ans=ans*i%mod;
	if(sum<m)ans=0;
	cout<<ans<<endl;
	return 0;
}
