#include<bits/stdc++.h>
using namespace std;
int n,m,c[105],sum[105],ans;
string s;
bool vis[505];
void dfs(int id,int num){
	if(id==n+1){
		if(num>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		if(sum[id]<c[i]&&s[id-1]=='1') dfs(id+1,num+1);
		else dfs(id+1,num);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		sum[i+1]=sum[i]+s[i-1]-'0';
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
