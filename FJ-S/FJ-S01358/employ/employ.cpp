#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int ans=0;
int n,m;
char s[N];
int b[N];
int c[N];
bitset<N> vis;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int day,int con){
	if(day==n && con<=n-m) ans=(ans+1)%mod;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(day+1,con+(s[day+1]=='0' || con>=c[i]));
		vis[i]=0;
	}
	return ;
}
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	vis.reset();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	//бнбн
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,(s[1]=='0' || c[i]==0));
		vis[i]=0;
	}
	//бнбн 
	cout<<ans;
	return 0;
}
