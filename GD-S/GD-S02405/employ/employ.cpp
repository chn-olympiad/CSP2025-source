#include<bits/stdc++.h>
#define int long long
//#define ll long long
using namespace std;
const int N=5e2+10,p=998244353;
int n,m,c[N],ans,sum,xxx;
bool vis[N];
char s[N];
void dfs(int ss,int x,int y){
	if(ss>n){
		if(y>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(s[ss]=='1'&&(x<c[i])) dfs(ss+1,x,y+1);
		else dfs(ss+1,x+1,y);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]) sum++;
	}
	if(sum<m){
		puts("0");
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
} 
