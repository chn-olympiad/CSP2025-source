#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0; char ch; bool f=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') f=1;
	else x=(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
bool st1;
const int N=2e5+5,M=5e6+5;
int n,q;
char ts[M],s1[M],s2[M];
struct strb{
	char s[M];
	int L[N],R[N];
	inline void ins(int i,int le){
		L[i]=R[i-1]+1; R[i]=R[i-1]+le;
		for(int j=1;j<=le;j++) s[L[i]+j-1]=ts[j];
	}
}t1,t2;
int L[N],R[N];
int ed[N][2];
struct stra{
	int Q[M];
	int rt;
	int ch[M][26],tot,fail[M];
	inline int ins(int le){
		int p=rt;
		for(int i=1;i<=le;i++){
			int c=ts[i]-'a';
			if(!ch[p][c]) ch[p][c]=++tot;
			p=ch[p][c];
		}
		return p;
	}
	int head[M],te;
	struct edge{
		int nex,y;
	}e[M<<1];
	inline void add(int x,int y){
		e[++te]={head[x],y}; head[x]=te;
	}
	int dfn[M],ed[M],cnt,rnk[M];
	inline void dfs(int x){
		dfn[x]=++cnt,rnk[cnt]=x;
		for(int i=head[x];i;i=e[i].nex){
			int y=e[i].y;
			dfs(y);
		}
		ed[x]=cnt;
	}
	inline void re(){
		int l=1,r=0;
		for(int i=0;i<26;i++){
			if(ch[rt][i]) Q[++r]=ch[rt][i];
		}
		while(l<=r){
			int x=Q[l]; l++;
			for(int i=0;i<26;i++){
				if(ch[x][i]){
					fail[ch[x][i]]=ch[fail[x]][i];
					Q[++r]=ch[x][i];
				}
				else ch[x][i]=ch[fail[x]][i];
			}
		}
		for(int i=1;i<=tot;i++){
//			cerr<<"add: "<<fail[i]<<" -> "<<i<<"\n";
			add(fail[i],i);
		}
		dfs(rt);
	}
}f1;
ll ans[N];
struct Opt{
	int p,q,id,bz;
}qu[M<<1];
int cnt;
struct Que{
	int head[M],tot;
	struct edge{
		int nex;
		int id;
	}e[M<<1];
	inline void add(int x,int y){
		e[++tot]={head[x],y}; head[x]=tot;
	}
}Q;
inline void ins(int p,int q,int id,int bz){
	cnt++; qu[cnt]={p,q,id,bz};
//	cerr<<"ins: "<<id<<": "<<f1.dfn[p]<<","<<f1.dfn[q]<<"!!"<<bz<<"\n";
	Q.add(f1.dfn[p],cnt);
}
struct R{
	int head[M],tot;
	struct edge{
		int nex,id;
	}e[N<<1];
	inline void add(int x,int y){
		e[++tot]={head[x],y}; head[x]=tot;
	}
}S;
struct strc{
	int s1[M];
	inline void ad(int x,int v){
		for(;x<=f1.cnt;x+=x&-x) s1[x]+=v;
	}
	inline void ad(int l,int r,int v){
		if(l>r) return;
//		cerr<<"ad: "<<l<<"~"<<r<<" "<<v<<"\n";
		ad(l,v),ad(r+1,-v);
	}
	inline int ask(int x){
		int t=0;
		for(;x>=1;x-=x&-x) t=t+s1[x];
//		cerr<<"ask: "<<x<<" "<<t<<"\n";
		return t;
	}
}f2;
inline void re(){
	f1.re();
	for(int i=1;i<=n;i++){
		int x=ed[i][0],y=ed[i][1];
		S.add(f1.dfn[x],i);
		S.add(f1.ed[x]+1,-i); 
//		cerr<<i<<": "<<x<<","<<y<<"-----------------\n";
//		cerr<<f1.dfn[x]<<"~"<<f1.ed[x]<<" "<<f1.dfn[y]<<"~"<<f1.ed[y]<<"!!\n";
	}
	for(int i=1;i<=q;i++){
		int l1=t1.R[i]-t1.L[i]+1;
		int l2=t2.R[i]-t2.L[i]+1;
		if(l1!=l2){
			ans[i]=0;
		}
		else{
			int st=1,ed=l1;
			while(st<=l1&&t1.s[t1.L[i]+st-1]==t2.s[t2.L[i]+st-1]) st++;
			while(ed>=1&&t1.s[t1.L[i]+ed-1]==t2.s[t2.L[i]+ed-1]) ed--;
			int p=f1.rt,le=0,q=f1.rt;
//			cerr<<i<<": "<<st<<"~"<<ed<<"\n";
			for(int j=t1.L[i],k=t2.L[i];j<=t1.R[i];j++,k++){
				le++; 
				int c;
				c=t1.s[j]-'a'; p=f1.ch[p][c];
				c=t2.s[k]-'a'; q=f1.ch[q][c];
				if(le>=ed){
//					cerr<<le<<"!!";
					ins(p,q,i,1);
				}
			}
			le=st; p=f1.rt,q=f1.rt;
			for(int j=t1.L[i]+st-1+1,k=t2.L[i]+st-1+1;j<=t1.R[i];j++,k++){
				le++;
				int c;
				c=t1.s[j]-'a'; p=f1.ch[p][c];
				c=t2.s[k]-'a'; q=f1.ch[q][c];
				if(le>=ed){
//					cerr<<le<<"!!";
					ins(p,q,i,-1);
				}
			}
		}
	}
	for(int i=1;i<=f1.cnt;i++){
		int x=f1.rnk[i];
		for(int j=S.head[i];j;j=S.e[j].nex){
			int id=S.e[j].id;
			if(id>0){
				int y=ed[id][1];
				f2.ad(f1.dfn[y],f1.ed[y],1);
			}
			else{
				int y=ed[-id][1];
				f2.ad(f1.dfn[y],f1.ed[y],-1);
			}
		}
		for(int j=Q.head[i];j;j=Q.e[j].nex){
			int ps=Q.e[j].id;
			int id=qu[ps].id,q=qu[ps].q;
			ans[id]=ans[id]+1ll*f2.ask(f1.dfn[q])*qu[ps].bz;
		}
	}
}
bool st2;
int main(){
//	cerr<<(&st1-&st2)/1024/1024; return 0;
//	system("fc replace4.ans replace.out"); return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ts+1); int ls=strlen(ts+1);
		ed[i][0]=f1.ins(ls);
		R[i]=R[i-1]+ls; L[i]=R[i-1]+1;
		for(int j=1;j<=ls;j++) s1[L[i]+j-1]=ts[j];
		scanf("%s",ts+1);
		ed[i][1]=f1.ins(ls);
		for(int j=1;j<=ls;j++) s2[L[i]+j-1]=ts[j];
	}
	for(int i=1;i<=q;i++){
		scanf("%s",ts+1); int ls=strlen(ts+1);
		t1.ins(i,ls);
		scanf("%s",ts+1); ls=strlen(ts+1);
		t2.ins(i,ls);
	}
	re();
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
/*
只能替换一次
AC自动机
对s[i][1]建AC自动机，然后拿t1在上面跑
可行的s[i][1]是fail树上的一条链
同理对s[i][2]建AC自动机，拿t2在上面跑
二维偏序
p1在ed[i][1]子树内
p2在ed[i][2]子树内 

x,y
l1[i]<=dfn[x]<=r1[i]
l2[i]<=dfn[y]<=r2[i]
对l1扫描线，[ l2[i],r2[i] ]区间加，单点查
差分 
*/
