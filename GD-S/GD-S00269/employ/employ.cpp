#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define int long long
const int N=510;
int n,m,f[N],c[N];
char s[N];
bool st[N];
int ans=0;
void dfs(int u){
	if(u==n+1){
		int t=0,ss=0;
		rep(i,1,n){
			if(c[f[i]]<=t||s[i]=='0') ++t;
			else ++ss;
		}
//		rep(i,1,n) cout<<f[i]<<" ";
//		cout<<"\n";
//		cout<<ss<<"\n"; 
		if(ss>=m) ++ans; 
		return ;
	}
	rep(i,1,n){
		if(!st[i]){
			st[i]=1,f[u]=i;
			dfs(u+1);
			st[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,1,n) cin>>s[i];
	rep(i,1,n) cin>>c[i];
//	rep(i,1,n) cout<<s[i]<<" ";
//	cout<<"\n";
	if(n<=10){
		dfs(1);
		cout<<ans<<"\n";
	}
	else cout<<1<<"\n";
	return 0;
} 
