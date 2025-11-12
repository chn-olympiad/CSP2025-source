#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const int L=2310;

bool p[L],q[L];

class AC{public:
	int a[L][26],t=1;
	int ins(char* s,int n){
		int u=1;for(int i=0;i<n;++i){
			if(!a[u][s[i]-'a']) a[u][s[i]-'a']=++t;
			u=a[u][s[i]-'a'];
		}return u;
	}
	int q[L],f[L],hd,tl;
	void bld(){
		q[hd=tl=1]=1;for(int i=0;i<26;++i) a[0][i]=1;
		while(hd<=tl){
			int u=q[hd++];
			for(int i=0;i<26;++i){
				if(!a[u][i]) a[u][i]=a[f[u]][i];
				else f[a[u][i]]=a[f[u]][i],q[++tl]=a[u][i];
			}
		}
	}
	void chk(){
		for(int i=1;i<=t;++i){
			printf("node %d f %d\n",i,f[i]);
			for(int c=0;c<26;++c) if(a[i][c]>1) printf("nxt %c: %d\n",c+'a',a[i][c]);
		}
	}
}A,B;

char s[L],t[L];int a[L],b[L],len[L],n;

int qry(){
	int l=strlen(s);if(l!=strlen(t)) return 0;
	int lst=n-1;while(s[lst]==t[lst]) --lst;
	int u=1,v=1,ans=0;for(int i=0,fst=-1;i<l;++i){
		if(s[i]!=t[i]&&!~fst) fst=i;
		u=A.a[u][s[i]-'a'];v=B.a[v][t[i]-'a'];
		if(i>=lst){
			memset(p,0,L);memset(q,0,L);int x=u,y=v;
			while(x!=1) p[x]=1,x=A.f[x];
			while(y!=1) q[y]=1,y=B.f[y];
			for(int j=1;j<=n;++j) if(p[a[j]]&&q[b[j]]&&len[j]>=i-fst+1) ++ans;
		}
	}
	return ans;
}

const int N=5141141;

namespace T{
	int s[N];void upd(int x,int d){
		while(x<N) s[x]+=d,x+=x&-x;
	}
	int qry(int x){
		int e=0;while(x) e+=s[x],x-=x&-x;
		return e;
	}
}

int fnd(char* s){
	for(int i=0;;++i) if(s[i]=='b') return i;
}

const int M=231231;

struct ifo{int l,r;bool operator<(const ifo &t)const{return l<t.l;}};
vector<ifo> vc[M];struct Q{ifo t;int id;};vector<Q> qr[M];

char u[N],v[N];int ans[M];

map<int,int> id;int cid;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;scanf("%d%d",&n,&q);
	if(q==1||n>1000||q>1000){
		for(int i=1;i<=n;++i){
			scanf("%s%s",u,v);int p=fnd(u),d=p-fnd(v);
			if(!id[d]) id[d]=++cid;
			vc[id[d]].push_back((ifo){p,strlen(u)-p});
		}
		for(int i=1;i<=cid;++i) sort(vc[i].begin(),vc[i].end());
		for(int i=1;i<=q;++i){
			scanf("%s%s",u,v);int l=strlen(u);if(l!=strlen(v)) continue;
			int p=fnd(u),d=p-fnd(v);if(!id[d]) continue;
			qr[id[d]].push_back((Q){(ifo){p,l-p},i});
		}
		for(int i=1;i<=cid;++i){
			auto p=vc[i].begin();
			for(auto q=qr[i].begin();q!=qr[i].end();++q){
				while(p!=vc[i].end()&&p->l<=q->t.l) T::upd(p->r,1),++p;
				ans[q->id]=T::qry(q->t.r);
			}
			for(auto q=vc[i].begin();q!=p;++q) T::upd(q->r,-1);
		}
		for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
		return 0;
	}
	for(int i=1;i<=n;++i) scanf("%s%s",s,t),len[i]=strlen(s),a[i]=A.ins(s,len[i]),b[i]=B.ins(t,len[i]);
	A.bld();B.bld();//A.chk();B.chk();return 0;
	while(q--) scanf("%s%s",s,t),printf("%d\n",qry());
}
//-Wconversion -Wshadow
/*
5 4
ab ba
aab aba
aab baa
aaab baaa
aaba baaa

aba baa
aabaa abaaa
aaaba baaaa
aaba baaa
*/
