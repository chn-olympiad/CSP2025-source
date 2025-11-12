#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
template <class Miaowu>
inline void in(Miaowu &x){
	char c;x=0;bool f=0;
	for(c=getchar();c<'0'||c>'9';c=getchar())f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
bool m_s;
const int N=2e5+5;
const int M=5e6+10;
char s1[M],s2[M];
string S1[N],T1[N],S2[N],T2[N];
int n,m,idr,ans[N],rec[M][52];
int h1[M],h2[M],id1,id2;
struct G1{int bh,nxt;}g1[N];
struct G2{int bh,nxt;}g2[N];
int t1[M>>1][26],t2[M>>1][26],c1,c2;
int ha[M],hq[M],ida,idq;
struct Add{int u,nxt;}add[N];
struct Qry{int u,id,nxt;}qry[N];
int dfn[M],siz[M],ind;
bool m_t;
inline void clear1(int u){
	for(int i=0;i<26;i++)if(t1[u][i])clear1(t1[u][i]),t1[u][i]=0;
}
inline void clear2(int u){
	for(int i=0;i<26;i++)if(t2[u][i])clear2(t2[u][i]),t2[u][i]=0;
}
inline void init(int u){
	dfn[u]=++ind,siz[u]=1;
	for(int i=0;i<26;i++)if(t2[u][i])init(t2[u][i]),siz[u]+=siz[t2[u][i]];
}
struct BIT{
	int t[M];
	inline void upd(int u,int x){
		while(u<=ind+1)t[u]+=x,u+=u&-u;
	}
	inline int qry(int u){
		int res=0;
		while(u)res+=t[u],u-=u&-u;
		return res;
	}
}bit;
inline void dfs(int u){
	for(int i=ha[u];i;i=add[i].nxt){
		int u=add[i].u;
		bit.upd(dfn[u],1),bit.upd(dfn[u]+siz[u],-1);
		// cout<<"?? "<<dfn[u]<<' '<<dfn[u]+siz[u]-1<<endl;
	}
	for(int i=hq[u];i;i=qry[i].nxt)ans[qry[i].id]=bit.qry(dfn[qry[i].u]);
	for(int i=0;i<26;i++)if(t1[u][i])dfs(t1[u][i]);
	for(int i=ha[u];i;i=add[i].nxt){
		int u=add[i].u;
		bit.upd(dfn[u],-1),bit.upd(dfn[u]+siz[u],1);
	}
}
inline void solve(int u){
	// cout<<"<< "<<u<<endl;
	for(int i=h1[u];i;i=g1[i].nxt){
		int j=g1[i].bh,u1=0,u2=0;
		for(char c:S1[j]){
			int o=(c-'a');
			if(!t1[u1][o])t1[u1][o]=++c1;
			u1=t1[u1][o];
		}
		for(char c:S2[j]){
			int o=(c-'a');
			if(!t2[u2][o])t2[u2][o]=++c2;
			u2=t2[u2][o];
		}
		qry[++idq]=Qry{u2,j,hq[u1]},hq[u1]=idq;
	}
	for(int i=h2[u];i;i=g2[i].nxt){
		// cout<<"??? "<<i<<' '<<g2[i].nxt<<endl;
		int j=g2[i].bh,u1=0,u2=0,fl=0;
		for(char c:T1[j]){
			int o=(c-'a');
			if(!t1[u1][o]){fl=1;break;}
			u1=t1[u1][o];
		}
		if(fl)continue;
		for(char c:T2[j]){
			int o=(c-'a');
			if(!t2[u2][o]){fl=1;break;}
			u2=t2[u2][o];
		}
		if(fl)continue;
		// cout<<"!! "<<j<<endl;
		add[++ida]=Add{u2,ha[u1]},ha[u1]=ida;
	}
	init(0),dfs(0);
	for(int i=0;i<=c1;i++)ha[i]=0;
	for(int i=0;i<=c2;i++)hq[i]=0;
	ida=idq=ind=0;
	clear1(0),clear2(0);
}
inline void Solve(int u){
	if(h1[u]&&h2[u])solve(u);
	for(int i=0;i<52;i++)if(rec[u][i])Solve(rec[u][i]);
}
int main(){
	// cerr<<(&m_t-&m_s)/1024/1024<<endl;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	in(n),in(m);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1),bg=1;
		while(bg<=len&&s1[bg]==s2[bg])bg++;
		if(bg>len)continue;
		int ed=len;
		while(ed>=1&&s1[ed]==s2[ed])ed--;
		int u=0;
		for(int j=bg;j<=ed;j++){
			int o=(s1[j]-'a');
			if(!rec[u][o])rec[u][o]=++idr;
			u=rec[u][o];
			o=(s2[j]-'a')+25;
			if(!rec[u][o])rec[u][o]=++idr;
			u=rec[u][o];
		}
		// if(h1[u])cout<<"!!!! "<<id1+1<<' '<<h1[u]<<endl;
		g2[++id2]=G2{i,h2[u]},h2[u]=id2;
		// cout<<u<<' '<<h1[u]<<endl;
		for(int j=bg-1;j>=1;j--)T1[i]+=s1[j];
		for(int j=ed+1;j<=len;j++)T2[i]+=s1[j];
	}
	for(int i=1;i<=m;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1),bg=1;
		if(len!=strlen(s2+1))continue;
		while(bg<=len&&s1[bg]==s2[bg])bg++;
		if(bg>len)continue;
		int ed=len;
		while(ed>=1&&s1[ed]==s2[ed])ed--;
		int u=0;
		for(int j=bg;j<=ed;j++){
			int o=(s1[j]-'a');
			if(!rec[u][o])rec[u][o]=++idr;
			u=rec[u][o];
			o=(s2[j]-'a')+25;
			if(!rec[u][o])rec[u][o]=++idr;
			u=rec[u][o];
		}
		g1[++id1]=G1{i,h1[u]},h1[u]=id1;
		for(int j=bg-1;j>=1;j--)S1[i]+=s1[j];
		for(int j=ed+1;j<=len;j++)S2[i]+=s1[j];
	}
	Solve(0);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}