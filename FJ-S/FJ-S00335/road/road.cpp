#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+15,M=1e6+1e5+5;
int n,m,k;
ll c[12],ans;
struct rd{
	int u,v;
	ll w;
} s[M];
int fa[N];
inline ll read() {
	ll x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
inline int getfa(int x) {
	if(x==fa[x]||!x) return x;
	return fa[x]=getfa(fa[x]);
}
inline ll kruskal(int r) {
	ll res=0ll;
	int sc=0;
	for(int j=1;j<=k;j++) {
		if((1<<(j-1))&r) res+=c[j],fa[n+j]=n+j,sc++;
		else fa[n+j]=0;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,cnt=0;cnt<=n+sc-1&&i<=m;i++) {
		int x=s[i].u,y=s[i].v,fx=getfa(x),fy=getfa(y);
		if(fy==fx||!fx||!fy) continue;
		fa[fx]=fy,res+=s[i].w,cnt++;
	}
	return res;
}
bool cmp(rd a,rd b) {
	return a.w<b.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) s[i].u=read(),s[i].v=read(),s[i].w=read();
	for(int i=1;i<=k;i++) {
		ll y;
		c[i]=read();
		for(int j=1;j<=n;j++) {
			y=read();
			s[++m].u=n+i,s[m].v=j,s[m].w=y;
		}
	}
	sort(s+1,s+1+m,cmp);
	for(int i=0;i<=(1<<k)-1;i++) {
		if(!ans) ans=kruskal(i);
		else ans=min(ans,kruskal(i));
	}
	cout<<ans;
	return 0;
}

