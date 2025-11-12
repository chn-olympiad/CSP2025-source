#include<bits/stdc++.h>
using namespace std;
int n,m,ans,c[502];
bool vis[502];
char s[505];
void dfs(int dea,int lq){
	if(dea+lq==n){
		if(lq>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(c[i]>dea&&s[dea+lq]=='1')dfs(dea,lq+1);
			else dfs(dea+1,lq);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(0,0);
	printf("%d",ans);
	return 0;
}
