#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353; 
int n,m,a[505],g[505],f[505],ans;
string s;
void dfs(int x){
	if(x>n){
		int sum=0,tot=0;
		for(int j=1;j<=n;j++){
			int i=g[j];
			if(s[j]=='1' && sum<a[i]) tot++;
			else sum++;
		}
		if(tot>=m) ans++;
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1) continue;
		f[i]=1; g[x]=i;
		dfs(x+1);
		f[i]=0; g[x]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s; s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
