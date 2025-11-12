#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int n,m,s[N],c[N],p[N];
int mod=998244353,ans;
int qm(int x){
	if(x>mod) return x-mod;
	else return x;
}
bool vis[N];
void dfs(int x,int sum,int mzc){
	if(x==n+1){
		if(sum>=m) ans=qm(ans+1);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1||i==p[x-1]) continue;
		vis[i]=1;
		p[x]=i;
		if(mzc>=c[i]||s[x]==0){
			dfs(x+1,sum,mzc+1);
		}else{
			dfs(x+1,sum+1,mzc);
		}
		vis[i]=0;
		p[x]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		p[i]=i;
	if(n<=18){
		dfs(1,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

