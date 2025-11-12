#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
int n,m,c[N],flag,cnt,vis[N];
ll ans,mod=998244353;
char s[N];
void dfs(int x,int impass){
	if(x>n){
		if(n-impass>=m){
			ans=(ans+1)%mod;
//			printf("%lld %d\n",ans,impass);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(impass>=c[i] || s[x]-'0'==0){
				dfs(x+1,impass+1);
			}
			else{
				dfs(x+1,impass);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+1+n);
	if(n<=10){
		dfs(1,0);
		printf("%lld",ans);
		return 0;
	}
	if(n==m){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!s[i]) flag=1;
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			if(!c[i]) cnt++;
		}
		if(n-cnt<m){
			printf("0");
			return 0;
		}
		else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			printf("%lld",ans);
			return 0;
		}
	}
	if(m==1){
		if(c[n]>=n){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			printf("%lld",ans);
			return 0;
		}
	}
}
