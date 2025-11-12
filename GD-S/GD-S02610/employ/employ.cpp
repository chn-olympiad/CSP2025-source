//8
#include<bits/stdc++.h>
using namespace std;
const int ZhuoJia=1;
const int MOD=998244353;
const int N=505;
int n,m;
string g;
int a[N],ans;
int vis[N];
int box[N],cnt;
int check(){
	int ren=0,f=0;
	for(int i=1;i<=n;i++){
		if(g[i-1]=='0'){
			f++;
		}else if(f>=box[i]){
			f++;	
		}else{
			ren++;
		}
	}
	return (ren>=m);
}
void dfs(int step){
	if(step==n){
		ans=(ans+check())%MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=1;
		box[++cnt]=a[i];
		dfs(step+1);
		cnt--;
		vis[i]=0;
	}
} 
void solve(){
	cin>>n>>m>>g;
	if(n>10){
		ans=ZhuoJia;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%MOD;
		}
		cout<<ans;
		return ;
	}
	for(int i=1;i<=n;i++)	cin>>a[i];
	dfs(0);
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	solve();
}
