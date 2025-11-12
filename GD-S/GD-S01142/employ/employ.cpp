#include <bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int maxn=510;
int nums[maxn],fail[maxn];
bool vis[maxn];
string s;
int n,m,ans;

void open(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
void input(){
	scanf("%d %d",&n,&m);
	cin >> s;
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i]);
	}
}
void dfs(int dep,int inp){
	//printf("DFS : %d %d\n",dep,inp);
	if(dep==n+1){
		if(inp>=m){
			//printf("-ans++\n");
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(fail[dep-1]>=nums[i] || s[dep]=='0'){
				dfs(dep+1,inp);
			}else{
				dfs(dep+1,inp+1);
			}
			vis[i]=0;
		}
	}
}
void solve(){
	s="*"+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			fail[i]=fail[i-1]+1;
		}
	}
	dfs(1,0);
}
void output(){
	printf("%d",ans);
}
int main(){
	open();
	input();
	solve();
	output();
	close();
	return 0;
}

