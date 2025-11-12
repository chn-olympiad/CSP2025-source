#include <bits/stdc++.h>
#define MAXN 10004
using namespace std;
using ll = long long;
int n,m,k;
struct edge{
	int u,v,w;
	bool operator<(const edge &b)const{
		return w<b.w;
	}
}e[1000006],t[MAXN],a[12][MAXN];
int fa[MAXN];
int c[MAXN];
int cur[12];
int tot;
int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
void init(){
	for(int i=1;i<=n+10;i++)fa[i]=i;
}
inline int read(){
	int x=0; int ch = getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	while(ch>='0' && ch<='9')x=x*10+ch-'0', ch=getchar();
	return x;
}
int main(){
#ifndef SVK
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	n=read(), m=read(), k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int w=read();
			a[i][j] = {n+i+1, j, w};
		}
	}
	init();
	sort(e+1,e+m+1);
	for(int i=0;i<k;i++)sort(a[i]+1,a[i]+n+1);
	for(int i=1;i<=m;i++){
		int u = fnd(e[i].u), v = fnd(e[i].v);
		if(u==v)continue;
		fa[u]=v; t[++tot]=e[i];
	}
	ll res = LLONG_MAX;
	for(int S=0;S<(1<<k);S++){		
		ll ans = 0;
		int qwq=n;
		for(int i=0;i<k;i++){
			if(!((S>>i)&1))continue;
			ans += c[i]; qwq++;
		}
		int cho = 0;
		using pii = pair<int,int>;
		priority_queue<pii,vector<pii>,greater<pii>> q;
		for(int i=0;i<k;i++){
			if(!((S>>i)&1))continue;
			q.push({a[i][1].w,i});
			cur[i]=1;
		}
		cur[k]=1; q.push({t[1].w,k});
		auto chk = [&](edge x){
			int u = fnd(x.u), v = fnd(x.v);
			if(u==v)return;
			cho++;
			fa[u]=v;
			ans += x.w;
		};
		init();
		while(!q.empty() && cho<qwq-1){
			int pos = q.top().second;
			q.pop();
			if(pos==k){
				chk(t[cur[k]]);
				cur[k]++;
				if(cur[k]<=tot)q.push({t[cur[k]].w, k});
			}else{
				chk(a[pos][cur[pos]]);
				cur[pos]++;
				if(cur[pos]<=n)q.push({a[pos][cur[pos]].w, pos});
			}
		}
		
		res = min(res, ans);
	}
	cout<<res<<"\n";
	return 0;
}

