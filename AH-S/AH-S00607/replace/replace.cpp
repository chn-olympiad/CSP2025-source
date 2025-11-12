#include<bits/stdc++.h>
using namespace std;
const int Maxn=5000005;
int n,Q,trie[Maxn][30],fail[Maxn],q[Maxn],hd,tl,ct[Maxn],tot,ans[Maxn],dep[Maxn];
char s1[Maxn],s2[Maxn];
int head[Maxn],val[Maxn],pre[Maxn],len;
int qhead[Maxn],qval[Maxn],qpre[Maxn],qid[Maxn],qlen;
void Ins(){
	int len=strlen(s1+1);bool flag=0;
	for(int i=1;i<=len;++i) if (s1[i]!=s2[i]) flag=1;
	if (!flag) return ;
	int u=0;
	for(int i=1;i<=len;++i){
		int c=s1[i]^96;
		if (!trie[u][c]){trie[u][c]=(++tot);dep[tot]=dep[u]+1;}
		u=trie[u][c];
		c=s2[i]^96;
		if (!trie[u][c]){trie[u][c]=(++tot);dep[tot]=dep[u]+1;}
		u=trie[u][c];
	}
	++ct[u];
}
void build(){
	hd=1,tl=0;
	for(int i=1;i<=26;++i) if (trie[0][i]) q[++tl]=trie[0][i];
	while(hd<=tl){
		int u=q[hd++];
		for(int i=1;i<=26;++i){
			if (!trie[u][i]) trie[u][i]=trie[fail[u]][i];
			else fail[q[++tl]=trie[u][i]]=trie[fail[u]][i];
		}
	}
}
void insq(int u,int v,int id){qpre[++qlen]=qhead[u];qhead[u]=qlen;qval[qlen]=v;qid[qlen]=id;}
void ins(int u,int v){pre[++len]=head[u];head[u]=len;val[len]=v;}
int stk[Maxn],top,sum[Maxn];
void dfs(int u){
	stk[++top]=dep[u];sum[top]=sum[top-1]+ct[u];
	for(int i=qhead[u];i;i=qpre[i]){
		if (qval[i]) ans[qid[i]]-=sum[lower_bound(stk+1,stk+1+top,qval[i])-stk-1];
		else ans[qid[i]]+=sum[top];
	}
	for(int i=head[u];i;i=pre[i]) dfs(val[i]);
	--top;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i){scanf("%s%s",s1+1,s2+1);Ins();}
	build();
	for(int i=1;i<=Q;++i){
		scanf("%s%s",s1+1,s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		if (len1!=len2){ans[i]=0;continue;}
		int L=0,R=0;
		for(int j=1;j<=len1;++j) if (s1[j]!=s2[j]){L=j;break;}
		for(int j=len1;j;--j) if (s1[j]!=s2[j]){R=j;break;}
		int u=0;
		for(int j=1;j<=len1;++j){
			u=trie[u][s1[j]^96];u=trie[u][s2[j]^96];
			if (j>=R){insq(u,0,i);insq(u,2*(j-L+1),i);}
		}
	}
	for(int i=1;i<=tot;++i) ins(fail[i],i);
	dfs(0);
	for(int i=1;i<=Q;++i) printf("%d\n",ans[i]);
	return 0;
}
