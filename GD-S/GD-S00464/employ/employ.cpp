#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,len;
string s1;
int c[N],pos[N],ans,vis[N],val[N];
void solve(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(s1[i]=='0'){
			res++;
			continue;
		}
		if(res>=val[i]){
			res++;
			continue;
		}
	}
	if(n-res>=m) ans++,ans%=mod;
}
void dfs(int x){
	if(x>n){
		solve();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			pos[x]=i,vis[i]=1,val[x]=c[i];
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++) cin>>c[i];
	s1=" "+s1;
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
