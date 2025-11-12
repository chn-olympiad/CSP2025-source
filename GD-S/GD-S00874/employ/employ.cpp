#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
string s;
int a[N];
int ans=0;
int pre[N];
bool vis[N];
int c[N];
void dfs(int p,int res){
	if(p==n+1&&res==m){
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		if(p-res>=c[i]||s[p]=='0'){
			dfs(p+1,res); 
		}else{
			dfs(p+1,res+1);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m; 
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			pre[i]=pre[i-1]+1;
		}else{
			pre[i]=pre[i-1];
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
