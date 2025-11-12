#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,MOD=998244353;
char s[N];
ll n,m,ans,a[N],c[N],p[N],vis[N];
void dfs(ll x,ll tt){
	if(n-tt<m)return ;//¼õÖ¦ 
	if(x>n){
		ans++;
//		for(int i=1;i<=x-1;i++){
//			printf("%lld ",p[i]);
//		}
//		puts("");
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			if(tt>=c[i]||a[x]==0)dfs(x+1,tt+1);
			else dfs(x+1,tt);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
		scanf("%lld",&c[i]);
	}
	if(n<=18){
		dfs(1,0);
		printf("%lld\n",ans);
		return 0;
	}
	else puts("0");
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
