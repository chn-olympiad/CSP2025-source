#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3 * 1e6 + 5;
inline int read(){
	int f = 0,k = 0;
	char c = getchar();
	while(!isdigit(c)){
		f |= c == '-';
		c = getchar();
	}
	while(isdigit(c)){
		k = k * 10 + c - '0';
		c = getchar();
	}
	return f ? -k : k;
}
int n,m,k;
int c[N],cnt,fa[N];
struct edge{
	int st,to,w;
	friend bool operator < (edge a,edge b){
		return a.w < b.w;
	}
}e[10000005];
int fd(int x){
	return fa[x] == x ? x : fa[x] = fd(fa[x]);
}
void uni(int x,int y){
	x = fd(x),y = fd(y);
	if(x != y) fa[x] = y;
}
void add(int u,int v,int w){
	e[++cnt] = (edge){u,v,w};
}
void kruskal(){
	sort(e + 1,e + 1 + cnt);
	int ans = 0,tot = 0; 
	for(int i = 1;i <= cnt;i++){
		int u = e[i].st,v = e[i].to,w = e[i].w;
		if(fd(u) != fd(v)){
			uni(u,v);
			++tot;
			ans += w;
			if(tot == n - 1){
				printf("%lld",ans);
				return ;
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 1;i <=  n + k + 1;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int u = read(),v = read(),w = read();
		add(u,v,w),add(v,u,w);
	}
	for(int i = 1;i <= k;i++){
		c[i + n] = read();
		for(int j = 1;j <= n;j++){
			int w = read();
			add(i + n,j,w);
			add(j,i + n,w); 
		}
	}
	kruskal();
	return 0;
}
