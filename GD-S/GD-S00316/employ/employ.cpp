#include<bits/stdc++.h>
using namespace std;
const int N=500,mod=998244353;
int n,m;
int ans;
int c[N+5];
char s[N+5];
int p[N+5];
bool vis[N+5];
void addv(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(cnt>=c[p[i]]){
			++cnt;
			continue;
		}
		if(s[i]=='0')
			++cnt;
	}
	return n-cnt>=m;
}
void dfs(int now){
	if(now==n+1){
		if(check())	
			addv(ans,1);
		return ;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			p[now]=i;
			vis[i]=true;
			dfs(now+1);
			vis[i]=false;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}

