#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int N=5e6+10;
int n,q,cnt=1,rt1[N],rt2[N],tot1,tot2,tr[N],ans[N],dfn[N],siz[N],tot;
string s,t;
struct node{
	int v;
	char c;
};
struct Tg{
	int v,d;
};
vector<int> bh[N];
vector<node> edge[N],edge1[N],edge2[N];
vector<Tg> tag[N];
inline void ins(string &s,string &t1,string &t2,int x,int op){
	int now=1;
	for(int i=1;i<(int)s.size();i++){
		int nxt=0;
		for(auto &j:edge[now])
			if(j.c==s[i]){
				nxt=j.v;
				break;
			}
		if(!nxt){
			if(op) return;
			nxt=++cnt,edge[now].push_back({nxt,s[i]});
		}
		now=nxt;
	}
	if(!rt1[now]) rt1[now]=++tot1,rt2[now]=++tot2;
	int now1=rt1[now];
	for(int i=1;i<(int)t1.size();i++){
		int nxt=0;
		for(auto &j:edge1[now1])
			if(j.c==t1[i]){
				nxt=j.v;
				break;
			}
		if(!nxt){
			if(!op) nxt=++tot1,edge1[now1].push_back({nxt,t1[i]});
			else break;
		}
		now1=nxt;
	}
	int now2=rt2[now];
	for(int i=1;i<(int)t2.size();i++){
		int nxt=0;
		for(auto &j:edge2[now2])
			if(j.c==t2[i]){
				nxt=j.v;
				break;
			}
		if(!nxt){
			if(!op) nxt=++tot2,edge2[now2].push_back({nxt,t2[i]});
			else break;
		}
		now2=nxt;
	}
	if(!op) bh[now1].push_back(now2);
	else tag[now1].push_back({now2,x});
}
inline void upd(int x,int y){
	for(;x<=tot;x+=lowbit(x))
		tr[x]+=y;
}
inline int qry(int x){
	int res=0;
	for(;x;x-=lowbit(x))
		res+=tr[x];
	return res;
}
inline void dfs(int u){
	dfn[u]=++tot,siz[u]=1;
	for(auto &i:edge2[u]){
		dfs(i.v);
		siz[u]+=siz[i.v];
	}
}
inline void dfs1(int u){
	for(auto &i:bh[u])
		upd(dfn[i],1),upd(dfn[i]+siz[i],-1);
	for(auto &i:tag[u])
		ans[i.d]=qry(dfn[i.v]);
	for(auto &i:edge1[u])
		dfs1(i.v);
	for(auto &i:bh[u])
		upd(dfn[i],-1),upd(dfn[i]+siz[i],1);
}
inline void solve(){
	cin>>n>>q;
	for(int i=1;i<=n+q;i++){
		cin>>s>>t;
		if(i<=n&&s==t) continue;
		if(i>n&&s.size()!=t.size()) continue;
		int siz=s.size(),l=0,r=0;
		s=" "+s,t=" "+t;
		for(int j=1;j<=siz;j++)
			if(s[j]!=t[j]){
				l=j;
				break;
			}
		for(int j=siz;j>=1;j--)
			if(s[j]!=t[j]){
				r=j;
				break;
			}
		string now=" ",now1=" ",now2=" ";
		for(int j=l;j<=r;j++)
			now+=s[j];
		for(int j=l;j<=r;j++)
			now+=t[j];
		for(int j=l-1;j>=1;j--)
			now1+=s[j];
		for(int j=r+1;j<=siz;j++)
			now2+=s[j];
		if(i<=n) ins(now,now1,now2,0,0);
		else ins(now,now1,now2,i-n,1);
	}
	for(int i=1;i<=cnt;i++)
		if(rt1[i]){
			tot=0;
			dfs(rt2[i]),dfs1(rt1[i]);
		}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}
