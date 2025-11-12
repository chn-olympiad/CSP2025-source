#include<bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define rep1(i,s,t) for(int i=s;i<t;i++)
#define frep(i,s,t) for(int i=s;i>=t;i--)
#define frep1(i,s,t) for(int i=s;i>t;i++)
#define mset(ai,k) memset(ai,k,sizeof(ai))
using namespace std;
const int N=1e6+5,mod=998244353;
int n,m,ci[N],ai[N],ans=0,f;
bool si[N],is1=1;
bool vis[N];
char c;
int md(int x){return x%mod;}
void dfs(int x){
	if(x>n){
		int sm=0;
		rep(i,1,n){
			if(!si[i]||sm>=ci[ai[i]])sm++;
		}
		if(n-sm<m)return;
	//	rep(i,1,n)cout<<ai[i]<<" ";
	//	cout<<endl;
		ans=md(ans+1);
		return;
	}
	rep(i,1,n)if(!vis[i])vis[i]=1,ai[x]=i,dfs(x+1),vis[i]=0;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m;
	rep(i,1,n)cin>>c,si[i]=c-'0',is1&=(si[i]==1);
	rep(i,1,n)cin>>ci[i];
	sort(ci+1,ci+1+n);
	dfs(1);
	cout<<ans<<endl;
}
