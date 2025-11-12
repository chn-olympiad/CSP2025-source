#include<bits/stdc++.h>
using namespace std;
#define N 505
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return f*a;
}
int n,m,mod=998244353;
int ans=0;
int c[N],s[N],jc[N],ls[N];
bool vis[N];
void dfs(int k,int cnt){
	if(cnt>n-m)return;
	if(k==n+1){
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		ls[k]=i;
		if(s[k]==0||c[i]<=cnt)dfs(k+1,cnt+1);
		else dfs(k+1,cnt);
		vis[i]=0;
	}
}
int f[N][N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	int lss=0;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*1ll*i%mod;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0',lss+=s[i];
	}
	for(int i=1;i<=n;i++)c[i]=read();
	sort(c+1,c+1+n);
	if(m==n){
		printf("0\n");
		return 0;
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
