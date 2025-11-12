#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define N 510
#define mod 998244353
int n,m;
bool s[N];
int c[N];
int vis[N];
int ans=0;
void dfs(int k,int sum){
	if(k>n){
		if(sum>=m)ans=(ans+1)%mod;
		return;
	}
	if(k-1-sum>n-m)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(s[k]&&k-1-sum<c[i])dfs(k+1,sum+1);
		else dfs(k+1,sum);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		char x;cin>>x;
		s[i]=(x=='1');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

