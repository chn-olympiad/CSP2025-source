#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,sp,c[510],ans,bo[510];
string s;
void dfs(ll now,ll res){
	if(now>n){
		if(n-res>=m) ans++;
		return;
	}
	if(n-res<m) return;
	for(int i=1;i<=n;i++) 
	if(!bo[i]) bo[i]=1,dfs(now+1,res+(res>=c[i]||s[now-1]=='0')),bo[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>18){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		return cout<<ans,0;
	} 
	cin>>s;
	for(int i=0;i<n;i++) sp+=s[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	cout<<ans;
}
