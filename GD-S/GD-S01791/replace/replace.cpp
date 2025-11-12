#include<bits/stdc++.h>
#define il inline
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define puu pair<ull,ull>
#define fir first
#define sec second
#define vi vector<int>
#define pb push_back
using namespace std;
namespace qwq {
const int N=2e5+10,M=5e6+10;
int n,m,ln;
char s[M],t[M],ss[M];
int nm[2],fi,se,tr[2][M][26],ps[2][2][N];
void ins(int o,char *s,int op,int j) {
//	puts(s+1);
	int u=1,ln=strlen(s+1);
	for(int i=1;i<=ln;i++) {
		int x=s[i]-'a';
		if(!tr[o][u][x]) tr[o][u][x]=++nm[o];
		u=tr[o][u][x];
	}
	ps[o][op][j]=u;
}
ull B=23333,hs[2][N],ht[2][N];
map<puu,int> mp;
int ct,vl[2][N];
int id[2],dfn[2][M],rk[2][M],sz[2][M];
vector<pii> vp[M],vq[M],vt[N*2];
void dfs(int o,int u) {
	dfn[o][u]=++id[o],rk[o][id[o]]=u,sz[o][u]=1;
	for(int i=0;i<26;i++) if(tr[o][u][i]) dfs(o,tr[o][u][i]),sz[o][u]+=sz[o][tr[o][u][i]];
}
struct BIT {
	int c[M];
	il int lbt(int id) {return id&-id;}
	il void upd(int id,int k) {for(;id<=nm[1];id+=lbt(id)) c[id]+=k;}
	il int qry(int id) {int r=0; for(;id;id-=lbt(id)) r+=c[id]; return r;}
	il void clr(int id) {for(;id<=nm[1];id+=lbt(id)) c[id]=0;}
} bit;
int as[N];
void main() {
	scanf("%d%d",&n,&m);
	nm[0]=nm[1]=1;
	for(int i=1;i<=n;i++) {
		scanf("%s%s",s+1,t+1),ln=strlen(s+1);
		fi=se=0;
		for(int j=1;j<=ln;j++) if(s[j]!=t[j]) {fi=j; break;}
		for(int j=ln;j;j--) if(s[j]!=t[j]) {se=j; break;}
		if(fi) {
			for(int j=fi;j<=se;j++) hs[0][i]=hs[0][i]*B+s[j],ht[0][i]=ht[0][i]*B+t[j];
			puu p={hs[0][i],ht[0][i]};
			if(!mp[p]) mp[p]=++ct;
			for(int i=1;i<fi;i++) ss[i]=s[fi-i];
			ins(0,ss,0,i);
			for(int i=1;i<=fi;i++) ss[i]=0;
			for(int i=1;i<=ln-se;i++) ss[i]=s[se+i];
			ins(1,ss,0,i);
			for(int i=1;i<=ln-se+1;i++) ss[i]=0;
		}
	}
//	cerr<<nm[0]<<" "<<nm[1]<<"\n";
	for(int i=1;i<=m;i++) {
		scanf("%s%s",s+1,t+1);
		int qwq=strlen(s+1),awa=strlen(t+1);
		if(qwq!=awa) continue;
		ln=qwq,fi=se=0;
		for(int j=1;j<=ln;j++) if(s[j]!=t[j]) {fi=j; break;}
		for(int j=ln;j;j--) if(s[j]!=t[j]) {se=j; break;}
		for(int j=fi;j<=se;j++) hs[1][i]=hs[1][i]*B+s[j],ht[1][i]=ht[1][i]*B+t[j];
		puu p={hs[1][i],ht[1][i]};
		if(!mp[p]) mp[p]=++ct;
		for(int i=1;i<fi;i++) ss[i]=s[fi-i];
		ins(0,ss,1,i);
		for(int i=1;i<=fi;i++) ss[i]=0;
		for(int i=1;i<=ln-se;i++) ss[i]=s[se+i];
		ins(1,ss,1,i);
		for(int i=1;i<=ln-se+1;i++) ss[i]=0;
	}
	for(int i=1;i<=n;i++) {
		vl[0][i]=mp[{hs[0][i],ht[0][i]}],vt[vl[0][i]].pb({i,0});
//		printf("9c99 %d\n",vl[0][i]);
	}
	for(int i=1;i<=m;i++) {
		vl[1][i]=mp[{hs[1][i],ht[1][i]}],vt[vl[1][i]].pb({i,1});
//		printf("1e11 %d\n",vl[1][i]);
	}
//	cerr<<"qwq\n";
	dfs(0,1),dfs(1,1);
	for(int h=1;h<=ct;h++) {
		for(pii p:vt[h]) {
			int i=p.fir,j=p.sec;
			if(!j) {
				int pl=ps[0][0][i],pr=ps[1][0][i];
				vp[dfn[0][pl]].pb({dfn[1][pr],1});
				vp[dfn[0][pl]].pb({dfn[1][pr]+sz[1][pr],-1});
				vp[dfn[0][pl]+sz[0][pl]].pb({dfn[1][pr],-1});
				vp[dfn[0][pl]+sz[0][pl]].pb({dfn[1][pr]+sz[1][pr],1});
			} else {
				int pl=ps[0][1][i],pr=ps[1][1][i];
				vq[dfn[0][pl]].pb({dfn[1][pr],i});
			}
		}
		for(int i=1;i<=nm[0];i++) {
			for(pii p:vp[i]) bit.upd(p.fir,p.sec);
			for(pii p:vq[i]) as[p.sec]=bit.qry(p.fir); 
		}
		for(int i=1;i<=nm[0];i++) for(pii p:vp[i]) bit.clr(p.fir);
		for(pii p:vt[h]) {
			int i=p.fir,j=p.sec;
			if(!j) {
				int pl=ps[0][0][i],pr=ps[1][0][i];
				vp[dfn[0][pl]].clear();
				vp[dfn[0][pl]].clear();
				vp[dfn[0][pl]+sz[0][pl]].clear();
				vp[dfn[0][pl]+sz[0][pl]].clear();
			} else {
				int pl=ps[0][1][i],pr=ps[1][1][i];
				vq[dfn[0][pl]].clear();
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d\n",as[i]);
}

}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	qwq::main();
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/ 
