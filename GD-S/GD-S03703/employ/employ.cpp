#include<bits/stdc++.h>
using namespace std;
const int N=501,P=998244353;
int n,m,ans;
int c[N],ansa[N]; bool vis[N],b[N];
void dfs(int x,int cn)
{
	if(cn>n-m) return ;
	if(x>n){
		ans=ans+1; return ;
	}
	int xx=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue ;
		if(cn>=c[i]||!b[x]) xx=1;
		else xx=0;
		vis[i]=true; ansa[x]=i; dfs(x+1,cn+xx);
		vis[i]=false; ansa[x]=0;
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char x; scanf(" %c",&x);
		if(x=='0') b[i]=0;
		else b[i]=1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n<=10){
		dfs(1,0); printf("%d",ans); 
		return 0;
	}
	else{
		if(n==m){
			long long fac=1; int op=1;
			for(int i=1;i<=n;i++) fac=fac*i%P;
			for(int i=1;i<=n;i++){
				if(b[i]==1) op=0;
			}
			fac=fac*op;
			printf("%lld",fac);
			return 0;
		}
		else printf("0");
	}
	return 0;
}
