#include<bits/stdc++.h>
#define ll long long
#define oF(l,r,i) for(int i=l;i<=r;i++)
#define of(l,r) for(int i=l;i<=r;i++)
#define tF(n,i) oF(1,n,i)
#define tf(n) oF(1,n,i)
#define nF(i) oF(1,n,i)
#define nf() oF(1,n,i)
#define pb emplace_back
#define pint pair<int,int>
#define mp make_pair
#define f first
#define s second
#define file(x) (freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),0)
using namespace std;
ll read(){
	ll x=0;
	char c=getchar();
	while(c<48)c=getchar();
	while(c>47)x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
int xxx=file(road);
int n=read(),m=read(),k=read();
#define edge pair<int,pair<short,short>>
#define v f
#define p1 s.f
#define p2 s.s
vector<edge>G,C[12],E[1024];
inline void merge(vector<edge>&ans,vector<edge>&a,vector<edge>&b){
	vector<edge>::iterator A=begin(a),B=begin(b);
	while(A!=end(a)&&B!=end(b)){
		if(A->f<B->f)ans.pb(*A++);
		else ans.pb(*B++);
	}
} 
int fa[10015];
int find(int x){return x^fa[x]?fa[x]=find(fa[x]):x;}
int w[12];
signed main(){
	nf()fa[i]=i;
	tf(m){
		int x=read(),y=read(),v=read();
		G.pb(mp(v,mp(x,y)));
	}
	sort(begin(G),end(G));
	for(edge e:G){
		short x=find(e.p1),y=find(e.p2);
		if(x^y){
			fa[x]=y;
			E[0].pb(e);
		}
	}
	tf(k){
		w[i]=read();
		nF(j)C[i].pb(mp(read(),mp(i+n,j)));
		sort(begin(C[i]),end(C[i]));
	}
	ll ans=1145141919810;
	for(int S=0;S<1<<k;S++){
		nf()fa[i]=i;
		ll now=0;
		if(S)merge(E[S],E[S&S-1],C[__lg(S&-S)+1]);
		tf(k)if(S>>i-1&1)now+=w[i],fa[i+n]=i+n;
		for(edge&e:E[S]){
			short x=find(e.p1),y=find(e.p2);
			if(x^y){
				fa[x]=y;
				now+=e.v;
			}
		}
		ans=min(ans,now);
	}
	write(ans);
}
