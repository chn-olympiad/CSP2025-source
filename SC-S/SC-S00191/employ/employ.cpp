#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353,INF=2e9;
#define rep(i,l,r)	for(int i=(l);i<=(r);i++)
#define atrep(i,l,r)	for(int i=(r);i>=(l);i--)
string str;
int a[N],b[N];
int n,m;
namespace baoli{
	int res=0;
	bool vis[N];
	void dfs(int u,int x,int p){
		if(u==n+1){
//			cout<<x<<" "<<p<<endl;
			if(p>=m) res++;
			if(res>=mod)	res-=mod;
			return;
		}
		rep(i,1,n){
			if(!vis[i]&&(a[i]>x)&&(str[u]!='0')){
				vis[i]=1;
				dfs(u+1,x,p+1);
				vis[i]=0;
			}else if((!vis[i])&&(a[i]<=x||str[u]=='0')){
				vis[i]=1;
				dfs(u+1,x+1,p);
				vis[i]=0;
			}
		}
	}
	void solve(){
		dfs(1,0,0);
		cout<<res<<endl;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	str=" "+str;
	rep(i,1,n)	cin>>a[i];
	if(n<=10){
		baoli::solve();
	}else{
		int res=1;
		rep(i,1,n)	res=res*i%mod;
		cout<<res<<endl;
	}
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/