#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c[505],p[505],vis[505],ans;
string s;
bool judge(){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(s[i-1]=='0'||cnt>=c[p[i]])cnt++;
		if(cnt>n-m)return false;
	}
	return true;
}
void dfs(ll c){
	if(c>n){
		if(judge()){
			ans++;
		}
		return;
	}
	for(p[c]=1;p[c]<=n;p[c]++){
		if(!vis[p[c]]){
			vis[p[c]]=1;
			dfs(c+1);
			vis[p[c]]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans%998244353;
	return 0;
}
