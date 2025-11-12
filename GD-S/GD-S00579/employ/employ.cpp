#include <bits/stdc++.h>
#define ll __int128
#define FRE
using namespace std;
ll read(){
	ll t1=0,t2=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')t2=-1;
		c=getchar();
	}while(c>='0' && c<='9')t1=t1*10+c-'0',c=getchar();
	return t1*t2;
}
void out(ll x){
	if(x<0)putchar('-'),out(-x);
	if(x>10)out(x/10),putchar(x%10+'0');
	else putchar(x+'0');
}
const ll N=501,MOD=998244353;
ll n,m,a[N],ans,c[N][N];
string s;
bool vis[N]; 
void dfs(ll x,ll gu,ll now){
	if(x>=n){
		if(now>=m)ans=(ans+1)%MOD;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i])continue;
		if(gu>=a[i]){vis[i]=1;dfs(x+1,gu+1,now);vis[i]=0;}
		else if(s[x]=='1'){vis[i]=1;dfs(x+1,gu,now+1);vis[i]=0;}
		else {vis[i]=1;dfs(x+1,gu+1,now);vis[i]=0;}
	}
}
int main(){
	#ifdef FRE
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif
	n=read();m=read();
	cin>>s;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=500;i++){
		c[i][1]=i;
		for(int j=2;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
		}
	}
	bool flag=0;int cnt=n;
	for(int i=0;i<n;i++){
		if(s[i]!='1')flag=1;
		if(a[i+1]==0)cnt--;	
	} 
	dfs(0,0,0);
	out(ans);
	return 0;
}

