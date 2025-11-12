#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int n,m,ans;
void slove();
struct node{
	int a,b,c;
}s[MAXN];
void dfs(int k,int cnt,int aw,int bw,int cw){
	if(aw>n/2||bw>n/2||cw>n/2) return ;
	if(k>=n){
		ans=max(ans,cnt);
		return ;
	}
	dfs(k+1,cnt+s[k+1].a,aw+1,bw,cw);
	dfs(k+1,cnt+s[k+1].b,aw,bw+1,cw);
	dfs(k+1,cnt+s[k+1].c,aw,bw,cw+1);
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		slove();
	}
	return 0;
}
void slove(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	}
	ans=0;
	dfs(0,0,0,0,0);
	cout<<ans<<'\n';
	return ;
}
