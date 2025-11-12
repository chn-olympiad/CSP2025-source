#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
const int mod=998244353;
long long ans;
string s;
bool v[505];
void dfs(int x,int y){
	if(x>n){
		if(y>=m) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=true;
		if(s[x-1]=='1'&&x-1-y<a[i]) dfs(x+1,y+1);
		else dfs(x+1,y);
		v[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bool f=true;
	for(int i=0;i<n;i++)
		if(s[i]!='1') f=false;
	if(f){
		ans=1;
		for(int i=2;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans; return 0;
	}
	dfs(1,0); cout<<ans;
	return 0;
}

