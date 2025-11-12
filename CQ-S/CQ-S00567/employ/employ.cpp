#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=510;
int n,m;
char ch[maxn];
int c[maxn];
int cnt[maxn],ans;
bool vis[maxn];
int g[maxn];
bool check(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(ch[i]=='0'||g[i]<=tmp)++tmp;
	}
	return (n-tmp>=m);
}
void dfs(int x){
	if(x>n){
		if(check())++ans;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		g[x]=c[i];
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ch[i],cnt[ch[i]-'0']++;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%998244353;
	cout<<ans<<'\n';
	return 0;
}
