#include<bits/stdc++.h>
using namespace std;
const int SS=26;
const int QS=2e5+5;
const int M=5e6+5;
int m=1;
int love[QS];//s->t 我喜欢你
vector<int>e[M];
vector<int>ids[M];
int dfn[M],mxd[M],tdfn=0;
int Len[M];
// int L1,L2;
namespace ACAM{
	int son[M][SS];
	int ins(int o,char *s,int len,bool op,int id){
		if(!o)o=++m;
		if(!len){//终止点
			if(op==0)ids[o].emplace_back(id);
			else love[id]=o;
			return o;
		}
		son[o][s[0]-'a']=ins(son[o][s[0]-'a'],s+1,len-1,op,id);
		return o;
	}//Tire
	int fail[M];
	int que[M],hd=0,tl=0;
	void build(){//建立 fail 树
		fail[1]=1;
		que[hd=tl=1]=1;
		Len[1]=0;
		while(hd<=tl){
			int u=que[hd++];
			for(int v,c=0;c<26;c++){
				v=son[u][c];if(!v)continue;
				Len[v]=Len[u]+1;
				fail[v]=fail[u];
				while(fail[v]!=1&&!son[fail[v]][c])fail[v]=fail[fail[v]];
				if(son[fail[v]][c]&&son[fail[v]][c]!=v)fail[v]=son[fail[v]][c];
				que[++tl]=v;
			}
		}
		for(int i=2;i<=m;i++){
			e[fail[i]].emplace_back(i);
		}
	}
	void match(char *s,int len,int *res){
		int u=1;
		for(int c,i=0;i<len;i++){
			c=s[i]-'a';
			while(u!=1&&!son[u][c])u=fail[u];
			if(son[u][c])u=son[u][c];
			res[i]=u;
		}
	}
}
int lb[M],fa[M],d[M];
void ADP(int u,int Fa){
	fa[u]=Fa,d[u]=d[Fa]+1;
	int x=lb[Fa],y=lb[x];
	if(d[x]-d[y]==d[Fa]-d[x])lb[u]=y;
	else lb[u]=Fa;
}
int jump(int u,int lim){
	while(Len[u]>lim){
		if(Len[lb[u]]>lim)u=lb[u];
		else u=fa[u];
	}
	return u;
}
void dfs1(int u,int Fa){
	ADP(u,Fa);
	dfn[u]=++tdfn;
	for(auto v:e[u])dfs1(v,u);
	mxd[u]=tdfn;
}
int Ans[M];
char s[M],t[M];
int ms[M],mt[M];
vector<pair<int,int> >qrs[M];
#define lowbit(x) (x&-x)
namespace BIT{
	int bit[M];
	void add(int x,int y){for(;x<=m;x+=lowbit(x))bit[x]+=y;}
	void adr(int l,int r,int x){add(l,x),add(r+1,-x);}
	int qry(int x){int res=0;for(;x;x-=lowbit(x))res+=bit[x];return res;}
}
#undef lowbit
void solve(int u){
	for(auto id:ids[u]){
		int x=love[id];
		BIT::adr(dfn[x],mxd[x],1);
	}
	for(auto qs:qrs[u]){
		int v=qs.first,id=qs.second;
		if(id>0)
			Ans[id]+=BIT::qry(dfn[v]);
		else
			Ans[-id]-=BIT::qry(dfn[v]);
	}
	for(auto v:e[u])solve(v);
	for(auto id:ids[u]){
		int x=love[id];
		BIT::adr(dfn[x],mxd[x],-1);
	}
}
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s,t);
		int len=strlen(s);
		// L1+=(len<<1);
		ACAM::ins(1,s,len,0,i);
		ACAM::ins(1,t,len,1,i);
	}
	ACAM::build();
	d[0]=0;
	dfs1(1,0);//建出树并建立斜二倍增
	for(int id=1;id<=q;id++){
		scanf("%s%s",s,t);
		int len=strlen(s),lent=strlen(t);
		// L2+=len+lent;
		if(len!=lent)continue;
		ACAM::match(s,len,ms);
		ACAM::match(t,len,mt);
		int fir=0;
		//要求排除：Len<=(i-fir)
		for(fir=0;fir<len&&s[fir]==t[fir];fir++);
		for(int i=len-1;i>=0;i--){
			int u=ms[i];
			qrs[u].emplace_back(make_pair(mt[i],id));
			u=jump(u,i-fir);
			if(u!=1)qrs[u].emplace_back(make_pair(mt[i],-id));
			if(s[i]!=t[i])break;
		}
	}
	// cerr<<L1<<" "<<L2<<"\n";
	solve(1);
	for(int id=1;id<=q;id++)printf("%d\n",Ans[id]);
	return 0;
}
//斜二倍增万岁！