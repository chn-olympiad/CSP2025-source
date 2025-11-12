#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rd(time(0));
const int N=2.5e6+5,M=5e6+5;
bool Mbe;
int n,q[N];char s1[M],s2[M];
struct ACAM{
	int tot=1,tr[N][26],nxt[N],cnt,L[N],R[N],d[N];
	vector<int> E[N];
	int ins(char *ch,int len){
		int u=1;
		for(int i=1;i<=len;i++){
			int c=ch[i]-'a';
			if(!tr[u][c])tr[u][c]=++tot;
			u=tr[u][c];
		} 
		d[u]=len;
		return u;
	}
	void dfs(int u){L[u]=++cnt;
		for(auto v:E[u])dfs(v);
		R[u]=cnt;
	}
	void bld(){int l=1,r=0;
		for(int i=0;i<26;i++)if(tr[1][i])q[++r]=tr[1][i],nxt[tr[1][i]]=1;else tr[1][i]=1;
		while(l<=r){int u=q[l++];
			for(int i=0;i<26;i++)
				if(tr[u][i])q[++r]=tr[u][i],nxt[tr[u][i]]=tr[nxt[u]][i];
				else tr[u][i]=tr[nxt[u]][i];
		}
		for(int i=2;i<=tot;i++)E[nxt[i]].push_back(i);
		dfs(1);
	}
}T1,T2;
vector<int> g1[N],g2[N],g3[N];
int tot;
struct Node{int i,x,d;}a[N];
void get(int I){
	int l1=strlen(s1+1),l2=strlen(s2+1);
	if(l1!=l2)return ;
	int x=0,y=l1+1;
	while(x+1<=l1&&s1[x+1]==s2[x+1])x++;
	while(y-1>=1&&s1[y-1]==s2[y-1])y--;
	for(int i=1,u=1,v=1;i<=l1;i++){
		u=T1.tr[u][s1[i]-'a'],v=T2.tr[v][s2[i]-'a'];
		if(i<y-1)continue ;
		int len=max(0,i-x);
		a[++tot]={I,u,len};
		g2[v].push_back(tot);
	}
}
int tp,st[N],d[N],c[N];
void U(int x,int v){for(;x<=T1.tot;x+=x&-x)c[x]+=v;}
int Q(int x){int s=0;for(;x;x^=x&-x)s+=c[x];return s;}
ll ans[N];
void dfs(int u){
	if(T2.d[u])st[++tp]=u,d[tp]=T2.d[u];
	for(auto x:g1[u])U(T1.L[x],1),U(T1.R[x]+1,-1);
	for(auto v:T2.E[u])dfs(v);
	if(!tp)return ;
	for(auto x:g2[u]){
		ans[a[x].i]+=Q(T1.L[a[x].x]);
		int p=lower_bound(d+1,d+tp+1,a[x].d)-d-1;
		if(p>0)g3[st[p]].push_back(x);
	}
	for(auto x:g3[u])ans[a[x].i]-=Q(T1.L[a[x].x]);
	for(auto x:g1[u])U(T1.L[x],-1),U(T1.R[x]+1,1);
	if(T2.d[u])--tp;
}
void write(ll x){
	if(x<10)return putchar(x^'0'),void();
	write(x/10),putchar((x%10)^'0');
} 
bool Med;
int main(){
//	cerr<<(&Mbe-&Med)/1024./1024.<<endl;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int Q;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		int a=T1.ins(s1,len),b=T2.ins(s2,len);
		g1[b].push_back(a);
	}
	T1.bld(),T2.bld();
	for(int i=1;i<=Q;i++)scanf("%s%s",s1+1,s2+1),get(i);
	dfs(1);
	for(int i=1;i<=Q;i++)write(ans[i]),puts("");
	return 0;
}

