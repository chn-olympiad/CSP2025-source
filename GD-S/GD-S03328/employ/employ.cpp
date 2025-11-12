#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,zer;
string s;
ll c[510],v[510];
bool vis[510];
const ll mod=998244353;
inline void dfs(ll i){
	if(i==n+1){
		ll tui=0,num=0;
		for(ll i=1;i<=n;i++){
			if(tui>=c[v[i]])tui++;
			else if(s[i]=='0')tui++;
			else num++;
		}
		if(num>=m)ans=(ans+1)%mod;
		return;
	}
	for(ll j=1;j<=n;j++){
		if(!vis[j]){
			v[i]=j,vis[j]=1;
			dfs(i+1);
			vis[j]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s,s=' '+s;
	for(ll i=0;i<s.size();i++)if(s[i]=='0')zer++;
	for(ll i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n){
		bool flag=1;
		if(zer>0)flag=0;
		for(ll i=1;i<=n;i++)if(c[i]==0)flag=0;
		if(flag=0){
			cout<<"0\n";
			return 0;
		}
		ll res=1;
		for(ll i=2;i<=n;i++)res=(res*i)%mod;
		cout<<res<<"\n";
		return 0;
	}
	if(m+zer>n){
		cout<<"0\n";
		return 0;
	}
	return 0;
} 
