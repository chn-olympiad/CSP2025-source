#include<bits/stdc++.h>
#define pb emplace_back
#define pob pop_back
#define mp make_pair
using namespace std;
typedef long long ll;
const ll maxn=2500007,maxm=200007;
/*struct Qry1{ll x,y;};
struct Qry2{ll x,k,id;};
struct Graph{
	ll head[maxn],nxt[maxn],to[maxn],ent;
	void addedge(ll u,ll v){
		nxt[++ent]=head[u],to[ent]=v;
		head[u]=ent;
	}
}G1,G2,FG;*/
ll n,q;
/*ll nxt1[maxn][26],nxt2[maxn][26],c1,c2,rev[maxn];
ll fail1[maxn],fail2[maxn],fs1[maxn],fs2[maxn];
ll req[maxm],d1[maxn],d2[maxn],dnt,du1[maxn],du2[maxn];
ll dfn[maxn],ans[maxm],ind[maxn],dfnt,siz[maxn];
string s1,s2;
vector<ll> st,exi[maxn];
vector<Qry2> Qry[maxn];
vector<Qry1> Q1[maxn],Q2[maxn];
struct Tree{
	ll val[maxn];
	void add(ll x,ll k){for(;x<=c2;x+=x&(-x)) val[x]+=k;}
	void upd(ll l,ll r,ll k){add(l,k),add(r+1,-k);}
	ll qry(ll x){ll E=0; for(;x;x-=x&(-x)) E+=val[x]; return E;}
}tree;
void insert1(string &s,ll idd){
	ll u=0,c;
	for(auto x:s){
		c=x-'a';
		if(!nxt1[u][c]) nxt1[u][c]=++c1;
		u=nxt1[u][c];
	}
	exi[u].pb(idd);
}
void insert2(string &s,ll idd){
	ll u=0,c;
	for(auto x:s){
		c=x-'a';
		if(!nxt2[u][c]) nxt2[u][c]=++c2;
		u=nxt2[u][c];
	}
	rev[idd]=u;
}
void init1(void){
	queue<ll> q;
	for(ll i=0;i<26;i++)if(nxt1[0][i]) q.push(nxt1[0][i]);
	for(ll u;!q.empty();){
		u=q.front(),q.pop();
		for(ll i=0;i<26;i++){
			if(nxt1[u][i]){
				fail1[nxt1[u][i]]=nxt1[fail1[u]][i],q.push(nxt1[u][i]);
				G1.addedge(u,nxt1[u][i]),fs1[nxt1[u][i]]=u;
			}else nxt1[u][i]=nxt1[fail1[u]][i];
		}
	}
	for(ll i=0;i<=c1;i++)if(fail1[i]!=i) FG1::addedge();
}
void init2(void){
	queue<ll> q;
	for(ll i=0;i<26;i++)if(nxt2[0][i]) q.push(nxt2[0][i]);
	for(ll u;!q.empty();){
		u=q.front(),q.pop();
		for(ll i=0;i<26;i++){
			if(nxt2[u][i]){
				fail2[nxt2[u][i]]=nxt2[fail2[u]][i],q.push(nxt2[u][i]);
				G2.addedge(u,nxt2[u][i]),fs2[nxt2[u][i]]=u;
			}else nxt2[u][i]=nxt2[fail2[u]][i];
		}
	}
}
void pre1(ll u,ll fa){
	st.pb(u);
	for(auto x:Q1[u]){
		if(st.size()<=req[x.x]) d1[x.y]=-1;
		else d1[x.y]=st[req[x.x]];
	}
	for(ll i=G1.head[u],v;i;i=G1.nxt[i]){
		v=G1.to[i];
		pre1(v,u);
	}
	st.pob();
}
void pre2(ll u,ll fa){
	st.pb(u),dfn[u]=++dfnt,siz[u]=1;
	for(auto x:Q2[u]){
		if(st.size()<=req[x.x]) d2[x.y]=-1;
		else d2[x.y]=st[req[x.x]];
	}
	for(ll i=G2.head[u],v;i;i=G2.nxt[i]){
		v=G2.to[i];
		pre2(v,u),siz[u]+=siz[v];
	}
	st.pob();
}
void dfs(ll u,ll fa){
	for(auto x:exi[u]) tree.upd(dfn[rev[x]],dfn[rev[x]]+siz[rev[x]]-1,1);
	for(auto x:Qry[u]) ans[x.id]+=tree.qry(x.x)*x.k;
	for(ll i=G1.head[u],v;i;i=G1.nxt[i]){
		v=G1.to[i];
		dfs(v,u);
	}
	for(auto x:exi[u]) tree.upd(dfn[rev[x]],dfn[rev[x]]+siz[rev[x]]-1,-1);
}*/
const ll P1=998244353,P2=1e9+7,B1=1145,B2=1919;
ll hs1[maxn],hs2[maxn],pw1[maxn],pw2[maxn],lth[maxn],ans;
ll ths1[maxn],ths2[maxn];
pair<ll,ll> hsh(ll l,ll r){return mp((hs1[r]-hs1[l-1]*pw1[r-l+1]%P1+P1)%P1,
(hs2[r]-hs2[l-1]*pw2[r-l+1]%P2+P2)%P2);}
int main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	/*for(ll i=1;i<=n;i++){
		cin>>s1>>s2;
		insert1(s1,i);
		insert2(s2,i);
	}
	init1(),init2();
	for(ll i=1,L,l,r;i<=q;i++){
		cin>>s1>>s2,L=s1.length();
		for(l=0;l<L;l++)if(s1[l]!=s2[l]) break;
		for(r=L-1;r>=0;r--)if(s1[r]!=s2[r]) break;
		req[i]=r-l+1;
		for(ll i=0,u1=0,u2=0,ch1,ch2;i<L;i++){
			ch1=s1[i]-'a',ch2=s2[i]-'a';
			if(i>r){
				Q1[u1].pb(Qry1{i,++dnt}),Q2[u2].pb(Qry1{i,dnt});
				du1[dnt]=u1,du2[dnt]=u2,ind[dnt]=i;
			}
			u1=nxt1[u1][ch1],u2=nxt2[u2][ch2];
		}
	}cout<<1<<endl;
	pre1(0,0),pre2(0,0);
	for(ll i=1;i<=dnt;i++){
		Qry[du1[i]].pb(Qry2{du2[i],1,ind[i]});
		Qry[d1[i]].pb(Qry2{du2[i],-1,ind[i]});
		Qry[du1[i]].pb(Qry2{d2[i],-1,ind[i]});
		Qry[d1[i]].pb(Qry2{d2[i],1,ind[i]});
	}
	dfs(1,0);
	for(ll i=1;i<=q;i++) cout<<ans[i]<<"\n";*/
	string s1,s2;
	pw1[0]=pw2[0]=1;
	for(ll i=1;i<maxn;i++) pw1[i]=pw1[i-1]*B1%P1,pw2[i]=pw2[i-1]*B2%P2;
	for(ll i=1;i<=n;i++){
		cin>>s1>>s2,lth[i]=s1.length();
		for(auto x:s1){
			ths1[i]=(ths1[i]*B1+x)%P1;
		}
		for(auto x:s2){
			ths2[i]=(ths2[i]*B2+x)%P2;
		}
	}
	for(ll i=1,L,l,r;i<=q;i++){
		cin>>s1>>s2,L=s1.length(),s1=" "+s1,s2=" "+s2;
		for(l=1;l<=L;l++)if(s1[l]!=s2[l]) break;
		for(r=L;r>=1;r--)if(s1[r]!=s2[r]) break;
		for(ll i=1;i<=L;i++){
			hs1[i]=(hs1[i-1]*B1+s1[i])%P1;
			hs2[i]=(hs2[i-1]*B2+s2[i])%P2;
		}
		ans=0;
		for(ll j=r;j<=L;j++){
			for(ll k=1;k<=n;k++)if(j-lth[k]+1<=l&&j-lth[k]+1>0&&hsh(j-lth[k]+1,j)==mp(ths1[k],ths2[k])) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}