#include<bits/stdc++.h>
#define ll long long
#define rep(i, j, k) for(int i=(j);i<=(k);++i)
#define rep1(i, j, k) for(int i=(k);i<=(j);--i) 
#define pii pair<int, int>
#define pb push_back
#define ft first
#define sd second

using namespace std;

int read(){
	int s=0, h=1;
	char x=getchar();
	while(!isdigit(x)){
		if(x=='-') h=-1;
		x=getchar();
	}
	while(isdigit(x)){
		s=(s<<3)+(s<<1)+x-'0';
		x=getchar();
	}
	return s*h;
}

void write(int x){
	if(x<0) putchar('-'), x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=1e4+5, M=1e6+5, K=15;
int n, m, k;
struct qwq{
	int u, v, w;
	bool friend operator < (qwq a, qwq b){
		return a.w < b.w;
	}
}e[M], b[K][N], s[1<<10][N+K];
int f[K][N], c[K];

int fa[N+K];
int find(int u){
	return u==fa[u] ? u : fa[u]=find(fa[u]);
}

int len[1<<10];
ll ans[1<<10], val[1<<10];

void hdl(int st, qwq a){
	int u=find(a.u), v=find(a.v);
	if(u==v) return;
	fa[v]=u;
	s[st][++len[st]]=a;
	ans[st]+=a.w;
}

int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n=read(), m=read(), k=read();
	rep(i, 1, m)
		e[i]=(qwq){read(), read(), read()};
	sort(e+1, e+m+1);
	
	rep(i, 1, k){
		c[i]=read();
		rep(j, 1, n)
			b[i][j]=(qwq){n+i, j, read()};
		sort(b[i]+1, b[i]+n+1);
	}
	rep(i, 1, n) fa[i]=i;
	rep(i, 1, m) hdl(0, e[i]);
	
	ll op=ans[0]+val[0];
	
	int mx=(1<<k)-1;
	rep(st, 1, mx){
		
		int id=log2(st&-st)+1;
		int lst=st^(st&-st);
		
		rep(i, 1, n+k) fa[i]=i;
		int i=1, j=1;
		while(i<=n && j<=len[lst]){
			if(b[id][i]<s[lst][j]) hdl(st, b[id][i++]);
			else hdl(st, s[lst][j++]);
		}
		while(i<=n) hdl(st, b[id][i++]);
		while(j<=len[lst]) hdl(st, s[lst][j++]);
		
		rep(i, 1, k) if((st>>(i-1))&1) val[st]+=c[i];
		
		op=min(op, ans[st]+val[st]);
	}
	
	cout<<op<<endl;
	
	return 0;
}// 15.28
