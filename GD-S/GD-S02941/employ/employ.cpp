#include<cstdio>
#include<cstring>
typedef long long ll;
const int N=1e6+8;
int n,m;
char s[N];
int c[N],sum[N],ans;
bool vis[N];
void dfs(int t,int tot){
	if(t>n){
		ans+=tot>=m;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		int can=s[t]=='1'&&sum[t]<c[i];
		dfs(t+1,tot+can);
		vis[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		sum[i]=sum[i-1]+s[i]=='1';
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
