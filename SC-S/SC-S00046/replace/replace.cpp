#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
using ll=long long;
bool Mst;
int n,q;
struct ACAM{
	int tr[M][26],fail[M],cnt;
	int L[M],R[M],pos[N],dfn;
	int head[M],to[M],nxt[M],tot;
	int dep[M];
	inline void add(int u,int v){nxt[++tot]=head[u],to[tot]=v,head[u]=tot;}
	inline int gtl(int x){return L[pos[x]];}
	inline int gtr(int x){return R[pos[x]];}
	inline void ins(string s,int id){
		int u=0;
		int len=s.length();
		for(int i=0;i<len;i++){
			int c=s[i]-'a';
			if(!tr[u][c])tr[u][c]=++cnt;
			u=tr[u][c]; 
		}
		pos[id]=u;
	}
	void dfs(int u){
		L[u]=++dfn;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			dep[v]=dep[u]+1;
			dfs(v);
		}
		R[u]=dfn;
	}
	inline void build(){
		queue<int>q;
		for(int i=0;i<26;i++){
			if(tr[0][i])q.push(tr[0][i]);
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<26;i++){
				if(!tr[u][i])tr[u][i]=tr[fail[u]][i];
				else fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
			}
		}
		for(int i=1;i<=cnt;i++)add(fail[i],i);
		dfs(0);
	}
}T1,T2;
int tk1[M],tk2[M];
ll ans[N];
struct node{
	int x,y,w,id;
	inline bool operator <(const node &B){
		return x<B.x;
	}
}rea[M<<1];
struct Pad{
	int pos,x,y,w;
	inline bool operator <(const Pad &B){
		return pos<B.pos;
	}
}pon[M];
struct BIT{
	int tr[M],cnt;
	inline void upd(int x,int v){
		while(x<=cnt)tr[x]+=v,x+=x&(-x);
	}
	inline void upd(int x,int y,int v){
		upd(x,v),upd(y+1,-v);
	}
	inline int qry(int x){
		int res=0;
		while(x){
			res+=tr[x];
			x-=x&(-x); 
		}
		return res;
	}
}T;
int pcnt,rcnt;
bool Med;
int main(){
	cerr<<(&Mst-&Med)/1024.0/1024.0<<"??\n";
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		T1.ins(s1,i);
		T2.ins(s2,i);
	}
	T1.build(),T2.build();
	T.cnt=T2.cnt+1;
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			ans[i]=0;
			continue;
		}
		int len=s1.length();
		int p1=0,p2=0;
		for(int j=0;j<len;j++){
			if(s1[j]^s2[j]){
				p1=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(s1[j]^s2[j]){
				p2=j;
				break;
			}
		}
		int u=0;
		for(int j=0;j<len;j++){
			int c=s1[j]-'a';
			u=T1.tr[u][c];
			tk1[j]=u;
		}
		u=0;
		for(int j=0;j<len;j++){
			int c=s2[j]-'a';
			u=T2.tr[u][c];
			tk2[j]=u;
			if(j>=p2&&tk1[j]&&tk2[j])
			rea[++rcnt]={T1.L[tk1[j]],T2.L[tk2[j]],1,i};
		}
		u=0;
		for(int j=0;j<len;j++){
			int c=s1[j]-'a';
			u=T1.tr[u][c];
			while(u&&T1.dep[u]>j-p1)u=T1.fail[u];
			tk1[j]=u;
		}
		u=0;
		for(int j=0;j<len;j++){
			int c=s2[j]-'a';
			u=T2.tr[u][c];
			while(u&&T2.dep[u]>j-p1)u=T2.fail[u];
			tk2[j]=u;
			if(j>=p2&&tk1[j]&&tk2[j])
			rea[++rcnt]={T1.L[tk1[j]],T2.L[tk2[j]],-1,i};
		}
	}
	sort(rea+1,rea+1+rcnt);
	for(int i=1;i<=n;i++){
		pon[++pcnt]={T1.gtl(i),T2.gtl(i),T2.gtr(i),1};
		pon[++pcnt]={T1.gtr(i)+1,T2.gtl(i),T2.gtr(i),-1};
//		cerr<<T1.gtl(i)<<" "<<T1.gtr(i)<<" "<<T2.gtl(i)<<" "<<T2.gtr(i)<<"!!!!\n";
	}
	sort(pon+1,pon+1+pcnt);
	int pos=1;
	for(int i=1;i<=rcnt;i++){
		while(pos<=pcnt&&pon[pos].pos<=rea[i].x)T.upd(pon[pos].x,pon[pos].y,pon[pos].w),pos++;
		ans[rea[i].id]+=rea[i].w*T.qry(rea[i].y);
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}