#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,m,s[505],c[505],ans=0;
bool vis[505];
void dfs(int x,int f){
	if(n-f<m)return ;
	if(x-1-f>=m){
		ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(s[x]==0||f>=c[i])
				dfs(x+1,f+1);
			else dfs(x+1,f);
			vis[i]=0;
		}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
