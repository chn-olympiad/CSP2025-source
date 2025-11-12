#include<bits/stdc++.h>
#define N 5000002
using namespace std;
int n,q;
int a[N];
int cnt,ch[N][26],f[N],t[N],w[N];
int c[N];
int fa[N][24],h[N][24];
int tot,head[N],nxt[N],to[N];
char s[2][N];
void add(int len){
	int now=0;
	for(int i=1;i<=len;i++){
		if(!ch[now][a[i]]) ch[now][a[i]]=++cnt,t[cnt]=i;
		now=ch[now][a[i]];
	}
	w[now]++;
}
void Add(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void build(){
	int l=1,r=0;
	for(int i=0;i<26;i++) if(ch[0][i]) c[++r]=ch[0][i];
	while(l<=r){
		int x=c[l];
		l++;
		for(int i=0;i<26;i++){
			if(ch[x][i]){
				f[ch[x][i]]=ch[f[x]][i];
				c[++r]=ch[x][i];
			} 
			else ch[x][i]=ch[f[x]][i];
		}
	} 
	for(int i=1;i<=cnt;i++) Add(f[i],i);
}
void dfs(int x,int F){
	fa[x][0]=F;
	h[x][0]=w[F];
	for(int i=1;i<=22;i++) fa[x][i]=fa[fa[x][i-1]][i-1],h[x][i]=h[x][i-1]+h[fa[x][i-1]][i-1]; 
	for(int i=head[x];i;i=nxt[i]) dfs(to[i],x);
}
void sol(int len){
	int now=0;
	long long ans=0;
	int l=len+1,r=0;
	for(int i=1;i<=len/2;i++) if(s[0][i]!=s[1][i]) l=min(l,i*2-1),r=max(r,i*2);
	for(int i=1;i<=len;i++){
		now=ch[now][a[i]];
		if(i<r||(i&1)) continue;
		int x=now,p=i-l+1;
		if(t[x]<p) continue;
		ans+=w[x];
		for(int j=22;j>=0;j--) if(t[fa[x][j]]>=p) ans+=h[x][j],x=fa[x][j];
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s[0]+1);
		scanf("%s",s[1]+1);
		int len=strlen(s[0]+1);
		for(int j=1;j<=len;j++) a[j*2-1]=s[0][j]-'a',a[j*2]=s[1][j]-'a';
		add(len*2);
	}
	build();
	dfs(0,cnt+1);
	for(int i=1;i<=q;i++){
		scanf("%s",s[0]+1);
		scanf("%s",s[1]+1);
		int len=strlen(s[0]+1);
		for(int j=1;j<=len;j++) a[j*2-1]=s[0][j]-'a',a[j*2]=s[1][j]-'a';
		sol(len*2);
	}
	return 0;
}
