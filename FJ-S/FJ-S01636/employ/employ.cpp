#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int d[100005];
int c[10005];
int cmp(int a,int b){
	return a>b;
}
int ans;
int vis[10005];
int cnt;
int g[10005];
void dfs(int x,int s){
	if(x==cnt+1){
		ans+=(s>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(c[i]>g[x]-s-1){
			dfs(x+1,s+1);
		}else{
			if(d[n]-(x-s)>=m){
				dfs(x+1,s);
			}
		}
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+s[i-1]-'0';
		if(s[i-1]=='1'){
			g[++cnt]=i;
		}
	}
	if(d[n]<m){
		cout<<0;
		return 0;
	}
//	if(d[n]==n){
//		cnt=0;
//		for(int i=1;i<=n;i++){
//			cnt+=(c[i]==0); 
//		}
//		ans=1;
//		for(int i=1;i<=n-cnt;i++){
//			ans=(ans*i)%998244353;
//		} 
//		cout<<ans;
//		return 0;
//	}
	sort(c+1,c+n+1,cmp);
	dfs(1,0);
	int p=1;
	for(int i=0;i<n-d[n];i++){
		p*=(n-d[n]-i);
		p%=998244353;
	}
	cout<<ans*p%998244353;
	return 0;
}
/*
3 2
101
1 1 2
*/
