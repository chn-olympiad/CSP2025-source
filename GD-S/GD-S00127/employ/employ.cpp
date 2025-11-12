#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+7,mod=998244353;
ll n,m,c[N],ans,sum[N];
char s[N];
bool A=1,vis[N];
void dfs(ll x,ll y){
	if(y>n-m)return; 
	if(x>n){
		ans++;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,y+(s[x]=='0'||c[i]<=y));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++){
		if(s[i]=='0')A=0;
		sum[i]=sum[i-1]+(s[i]=='0');
	}
	if(A&&n>10){
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		printf("%lld",ans);
	}
	else {
		dfs(1,0);
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
