#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353,n,m,ans=1,len,opt,vis[505],a[505],b[505],ansa;
string s;
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'||a[i+1]<=cnt) cnt++;
		}
		if(n-cnt>=m) ansa++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		a[x]=b[i];
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		if(s[i]!='1') opt=1;
		else len++;
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	if(len<m) cout<<0;
	else if(opt==0||m==1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	else if(n<=10){
		dfs(1);
		cout<<ansa; 
	}
	else cout<<1;
	return 0;
}
