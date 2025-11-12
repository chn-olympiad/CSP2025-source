#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char s[505];
int c[505];
ll ans=0;
bool vis[505];
void dfs(int x,int y){
	if(n-y<m)return;
	if(n-y>=m&&x==n+1){
		ans++;
		ans%=998244353;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(s[x]=='0'||c[i]<=y){
			vis[i]=1;
			dfs(x+1,y+1);
			vis[i]=0;
		}
		else{
			vis[i]=1;
			dfs(x+1,y);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n>=18){
		dfs(1,0);
		printf("%lld",ans);
	}
	else printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
