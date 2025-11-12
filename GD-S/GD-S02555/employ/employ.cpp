#include<iostream>
using namespace std;
#define mod 998244353
const int N=(1<<18)+19;
bool vis[555];
int n,m,ans,f[555],dp[N][22],c[555];
void solve(int x,int p,int wa){
	if(p==n){
		if(n-wa>=m)dp[x][wa]=1;
		return ;
	}
	if(dp[x][wa]) return ;
	for(int i=0;i<n;i++){
		if(x&(1<<i)) continue;
		solve(x|(1<<i),p+1,wa+((!f[p])||wa>=c[i]));
		dp[x][wa]+=dp[x|(1<<i)][wa+((!f[p])||wa>=c[i])];
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		f[i]=c-'0';
	}
	for(int i=0;i<n;i++) cin>>c[i];
	solve(0,0,0);
	cout<<dp[0][0];
	return 0;
}
