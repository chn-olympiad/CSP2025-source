#include<iostream>
#include<string>
using namespace std;
int n,m,c[505],vis[505],p=998244353;
long long ans;
string s;
void dfs(int u,int out){
	if(n-out<m)return;
	if(u>n){
		if(n-out==m)ans=(ans+1)%p;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(out>=c[i]||s[u-1]=='0')dfs(u+1,out+1);
		else dfs(u+1,out);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
