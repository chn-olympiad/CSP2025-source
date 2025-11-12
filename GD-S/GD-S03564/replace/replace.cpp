#include<bits/stdc++.h>
#define Mp make_pair
#define eb emplace_back
#define il inline
#define pc putchar
#define gc getchar
#define mems(x,y) memset(x,y,sizeof x)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define drep(i,x,y) for(int i=(x);i>=(y);i--)
#define go(i,u) for(int i=head[u];i;i=e[i].nxt)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e3+7,M=-1,inf=0x3f3f3f3f,mod=0;
const ll INF=1ll*inf*inf;
int n,q,len[N],fail[N][N][2];
char s[N][N],t[N][N],S[N],T[N];
void Sana(){
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%s%s",s[i]+1,t[i]+1);
		len[i]=strlen(s[i]+1);
		rep(j,2,len[i]){
			int p=fail[i][j-1][0];
			while(p&&s[i][j]!=s[i][p+1]){
				p=fail[i][p][0];
			}
			if(s[i][j]==s[i][p+1]){
				p++;
			}
			fail[i][j][0]=p;
		}
		rep(j,2,len[i]){
			int p=fail[i][j-1][1];
			while(p&&t[i][j]!=t[i][p+1]){
				p=fail[i][p][1];
			}
			if(t[i][j]==t[i][p+1]){
				p++;
			}
			fail[i][j][1]=p;
		}
	}
	while(q--){
		scanf("%s%s",S+1,T+1);
		int m=strlen(S+1);
		int l=1,r=m;
		while(S[l]==T[l])l++;
		while(S[r]==T[r])r--;
		int ans=0;
		rep(i,1,n){
			int u=0,v=0;
			rep(j,1,m){
				while(u&&S[j]!=s[i][u+1]){
					u=fail[i][u][0];
				}
				if(S[j]==s[i][u+1]){
					u++;
				}
				while(v&&T[j]!=t[i][v+1]){
					v=fail[i][u][1];
				}
				if(T[j]==t[i][v+1]){
					v++;
				}
				if(u==len[i]&&v==len[i]&&j>=r&&j-len[i]+1<=l){
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t=1;
	// scanf("%d",&t);
	while(t--){	
		Sana();
	}
}
/*
Shamefully, not be able to finish it.
#include<bits/stdc++.h>
#define Mp make_pair
#define eb emplace_back
#define il inline
#define pc putchar
#define gc getchar
#define mems(x,y) memset(x,y,sizeof x)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define drep(i,x,y) for(int i=(x);i>=(y);i--)
#define go(i,u) for(int i=head[u];i;i=e[i].nxt)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=4e5+7,M=2.5e6+7,inf=0x3f3f3f3f,mod=0;
const ll INF=1ll*inf*inf;
int n,m,q,c[N],L[N],R[N],ans[N];
char s[M],t[M];
vector<int> ad[N];
vector<tuple<int,int,int>> qr[N];
struct ACAM{
	int cur,pos[N],tr[M][26],fail[M],len[M];
	bool vis[M];
	int Cur,dep[M],dfn[M],rk[M],fa[M],pre[M],id[M],ref[N];
	int Tr[M<<2];
	vector<int> G[N];
	int tot,head[M];
	struct node{
		int to,nxt;
	}e[M];
	il void add(int u,int v){
		e[++tot]={v,head[u]};
		head[u]=tot;
	}
	void ins(char *s,int i){
		int m=strlen(s+1),u=0;
		rep(i,1,m){
			int v=s[i]-'a';
			if(!tr[u][v]){
				tr[u][v]=++cur;
			}
			len[tr[u][v]]=len[u]+1;
			u=tr[u][v];
		}
		pos[i]=u,vis[u]=1;
	}
	void dfs(int u,int f){
		rk[dfn[u]=++Cur]=u;
		dep[u]=dep[fa[u]=f]+1;
		go(i,u){
			int v=e[i].to;
			dfs(v,u);
		}
	}
	void dfs1(int u){
		pre[u]=pre[fa[u]];
		if(id[u]&&u){
			G[pre[u]].eb(id[u]);
			dfn[id[u]]=++cur,fa[u]=pre[u];
			pre[u]=id[u],ref[id[u]]=u;
		}
		go(i,u){
			int v=e[i].to;
			dfs1(v);
		}
	}
	il int Max(int x,int y){
		return x&y?(dep[x]<dep[y]?x:y):x|y;
	}
	void bld(int l,int r,int u){
		if(l==r){
			Tr[u]=rk[l];
			return;
		}
		int mid=(l+r)>>1;
		bld(l,mid,u<<1),bld(mid+1,r,u<<1|1);
		Tr[u]=Max(Tr[u<<1],Tr[u<<1|1]);
	}
	int qry(int l,int r,int u,int x,int y){
		if(r<x||l>y){
			return 0;
		}
		if(l>=x&&r<=y){
			return Tr[u];
		}
		int mid=(l+r)>>1;
		return Max(qry(l,mid,u<<1,x,y),qry(mid+1,r,u<<1|1,x,y));
	}
	void bld(){
		queue<int> q;
		rep(i,0,25){
			if(tr[0][i]){
				q.push(tr[0][i]);
			}
		}
		while(q.size()){
			int u=q.front();
			q.pop();
			rep(i,0,25){
				if(tr[u][i]){
					fail[tr[u][i]]=tr[fail[u]][i];
					q.push(tr[u][i]);
				}else{
					tr[u][i]=tr[fail[u]][i];
				}
			}
		}
		vector<int> vec,Vec;
		vec.eb(0);
		rep(u,1,cur){
			add(fail[u],u);
			// printf("%d %d\n",fail[u],u);
			if(vis[u]){
				vec.eb(u);
				// printf("%d\n",u);
			}
		}
		dfs(0,0);
		sort(vec.begin(),vec.end(),[&](int x,int y){return dfn[x]<dfn[y];});
		bld(1,cur,1);
		rep(i,0,(int)vec.size()-2){
			Vec.eb(vec[i+1]);
			Vec.eb(fa[qry(1,cur,1,dfn[vec[i]+1],dfn[vec[i+1]])]);
		}
		swap(vec,Vec);
		sort(vec.begin(),vec.end(),[&](int x,int y){return dfn[x]<dfn[y];});
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		int pid=0;
		for(int u:vec){
			id[u]=++pid;
		}
		dfn[id[0]]=cur=1;
		dfs1(0);
		rep(i,1,n){
			// printf("%d %d %d\n",i,pos[i],id[pos[i]]);
			pos[i]=id[pos[i]];
		}
	}
}T[2];
void dfs(int u){
	for(int v:ad[u]){
		c[v]++;
		// printf("%d %d\n",u,v);
	}
	for(auto [i,j,v]:qr[u]){
		while(v){
			// printf("%d\n",T[1].len[T[1].ref[v]]);
			if(T[1].len[T[1].ref[v]]<j-L[i]+1){
				v=T[1].fa[v];
				continue;
			}
			ans[i]+=c[v];
			v=T[1].fa[v];
		}
		// puts("**");
	}
	for(int v:T[0].G[u]){
		dfs(v);
	}
	for(int v:ad[u]){
		c[v]--;
	}
}
void Sana(){
	scanf("%d%d",&n,&q);	
	rep(i,1,n){
		scanf("%s%s",s+1,t+1);
		T[0].ins(s,i),T[1].ins(t,i);
	}
	T[0].bld(),T[1].bld();
	// return;
	rep(i,1,n){
		ad[T[0].pos[i]].eb(T[1].pos[i]);
		// printf("%d %d\n",T[0].pos[i],T[1].pos[i]);
	}
	rep(i,1,q){
		scanf("%s%s",s+1,t+1);
		int m=strlen(s+1);
		L[i]=1,R[i]=m;
		while(s[L[i]]==t[L[i]]){
			L[i]++;
		}
		while(s[R[i]]==t[R[i]]){
			R[i]--;
		}
		int u=0,v=0;
		rep(j,1,m){
			int x=s[j]-'a',y=t[j]-'a';
			u=T[0].tr[u][x],v=T[1].tr[v][y];
			if(j>=R[i]){
				qr[T[0].pre[u]].eb(i,j,T[1].pre[v]);
			}
		}
	}
	dfs(0);
	rep(i,1,q){
		printf("%d\n",ans[i]);
	}
}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int t=1;
	// scanf("%d",&t);
	while(t--){	
		Sana();
	}
}
*/