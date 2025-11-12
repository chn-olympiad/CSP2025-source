#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int MOD=998244353;
int c[N];
bool vis[N];
int n,m;
long long ans=0;
string s;
void dfs(int x,int cnt){
	if(n-x+1+cnt<m)	return;
	if(x==n+1){
		if(cnt>=m)	ans=(ans+1)%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=1;
		if(x-1-cnt>=c[i]||s[x-1]=='0'){
			dfs(x+1,cnt);
		}
		else	dfs(x+1,cnt+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans<<'\n';
	
	return 0;
} 
