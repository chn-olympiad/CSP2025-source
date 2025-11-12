#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define psb push_back
#define lowbit(x) (x&-x)
#define pii pair<ll,ll>
#define ppi pair<pii,int>
#define x first
#define y second
const int N=2e6+10,L=5e6+10,B1=373,B2=557,P1=999977219,P2=999976169;
int n,m,q,tot,ans[N],tr[N],id[N],a1[N],a2[N],nxt[L][26];//,vis[N];
string s1,s2,s[N],pre,suf;
vector<int>v[L];
map<ppi,int>rt;
struct A{int rt,id;};
vector<A>mp[N];
inline void upt(int x,int k){
	if(x)
		for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
}
inline int qry(int l,int r){
	int ans=0;
	for(int i=r;i;i-=lowbit(i)) ans+=tr[i];
	for(int i=l-1;i;i-=lowbit(i)) ans-=tr[i];
	return ans;
}
inline void ins(int x,string s,int id){
	int p=x;
	for(char c:s){
		if(!nxt[p][c-'a']) nxt[p][c-'a']=++tot;
		p=nxt[p][c-'a'];
	}
	v[p].psb(id);
}
inline ll cal1(string s){
	ll ans=0;
	for(char c:s) ans=(ans*B1+c)%P1;
	return ans;
}
inline ll cal2(string s){
	ll ans=0;
	for(char c:s) ans=(ans*B2+c)%P2;
	return ans;
}
inline int dfs1(int x,string s){
	int p=x;
	for(char c:s){
		if(!nxt[p][c-'a']) return p;
		p=nxt[p][c-'a'];
	}
	return p;
}
inline void dfs2(int x){
	for(int i:v[x]) id[i]=++tot;
	for(int i=0;i<26;++i)
		if(nxt[x][i]) dfs2(nxt[x][i]);
}
inline void dfs3(int x){
	for(int i:v[x]) upt(id[i],1);
	for(A i:mp[x]){
		int p=i.rt,sum=0;
		if(v[p].size()) sum+=qry(id[v[p][0]],id[*--v[p].end()]);
		for(char c:s[i.id]){
			if(!nxt[p][c-'a']) break;
			p=nxt[p][c-'a'];
			if(v[p].size()) sum+=qry(id[v[p][0]],id[*--v[p].end()]);
		}
		ans[i.id]=sum;
	}
	for(int i=0;i<26;++i)
		if(nxt[x][i]) dfs3(nxt[x][i]);
	for(int i:v[x]) upt(id[i],-1);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1>>s2; m=s1.size();
		if(s1==s2) continue;
		int l,r,h1,h2;
		for(int j=0;;++j)
			if(s1[j]!=s2[j]){l=j; break;}
		for(int j=m-1;;--j)
			if(s1[j]!=s2[j]){r=j; break;}
		pii h={cal1(s1.substr(l,r-l+1)),cal2(s2.substr(l,r-l+1))};
		pre=s1.substr(0,l),reverse(pre.begin(),pre.end()),suf=s1.substr(r+1,m-r-1);
		if(!rt.count({h,1})) rt[{h,1}]=++tot;
		if(!rt.count({h,2})) rt[{h,2}]=++tot;
		ins(rt[{h,1}],pre,i),ins(rt[{h,2}],suf,i);
	}
	for(int i=1;i<=q;++i){
		cin>>s1>>s2; m=s1.size();
		if(s1.size()!=s2.size()) ans[i]=0;
		else{
			int l,r,h1,h2;
			for(int j=0;;++j)
				if(s1[j]!=s2[j]){l=j; break;}
			for(int j=m-1;;--j)
				if(s1[j]!=s2[j]){r=j; break;}
			pii h={cal1(s1.substr(l,r-l+1)),cal2(s2.substr(l,r-l+1))};
			pre=s1.substr(0,l),reverse(pre.begin(),pre.end()),suf=s1.substr(r+1,m-r-1);
			mp[dfs1(rt[{h,1}],pre)].psb({rt[{h,2}],i}),s[i]=suf;
		}
	}
	tot=0;
	for(auto i:rt)
		if(i.x.y==2) dfs2(i.y);
	for(auto i:rt)
		if(i.x.y==1) dfs3(i.y);
	for(int i=1;i<=q;++i) cout<<ans[i]<<'\n';
	return 0;
}
