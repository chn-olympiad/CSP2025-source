#include<bits/stdc++.h>
using namespace std;
#define ll int
#define LL long long
ll read(){
	ll rs=0,w=1;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')w=-1,c=getchar();
	while('0'<=c&&c<='9'){
		rs=rs*10+c-'0';c=getchar();
	}
	return rs*w;
}
const ll N=510,mod=998244353;
bool s[N];ll c[N];
ll p[N],n,m;bool vis[N];
bool check(){
	ll fq=0,sm=0;
	for(ll i=1;i<=n;i++){
//		cout<<i<<' '<<fq<<'\n';
		if(fq>=c[p[i]]||!s[i])fq++;
		else sm++;
	}
//	puts("");
	return sm>=m;
}
ll as=0;
void dfs(ll id){
	if(id>n){
		as+=check();as%=mod;return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[id]=i;
		dfs(id+1);
		vis[i]=0;
	}
}
ll dp[N][N];
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout); 
	n=read(),m=read();
	string ss;cin>>ss;
	bool flg=1;
	for(ll i=1;i<=n;i++){
		s[i]=ss[i-1]-'0';
		flg&=s[i];
	}
	for(ll i=1;i<=n;i++)c[i]=read();
	dfs(1);
	cout<<as;
	
}
