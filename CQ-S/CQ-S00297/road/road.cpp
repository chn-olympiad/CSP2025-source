#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 1000005
#define intl long long
#define For(i,a,b) for(intl i = a;i <= b;i ++)
#define deo(i,a,b) for(intl i = a;i >= b;i --)
intl read() {
	intl x = 0, k = 1;char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') k = -1; ch = getchar();}
	while(isdigit(ch)) x = (x<<3) + (x<<1) + (ch^48), ch=getchar();
	return x*k;
}
struct node{
	intl u,v,w;
	bool operator < (const node&a) const{
		return w < a.w;
	} 
}e[M],g[M],ee[M];
intl n,m,k,a[20][N], fa[M], ans,tot = 0;
intl cnt[M];
intl get(intl x) {return x^fa[x]?fa[x] = get(fa[x]):x;}
void krs() {
	sort(e+1,e+m+1);
	For(i,1,n) fa[i] = i;
	For(i,1,m) {
		intl fu = get(e[i].u), fv = get(e[i].v);
		if(fu != fv) {
			g[++tot] = e[i];
			ans += e[i].w;
			fa[fu] = fv;
		}
		if(tot == n-1) return ;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(), m = read(), k =read();
	For(i,1,m) {
		intl u = read(), v = read(), w = read();
		e[i]={u,v,w};
	} 
	For(i,1,k) For(j,0,n) a[i][j] = read();
	krs();sort(g+1,g+tot+1);
	For(s,0,(1<<k)-1) {
		intl qwe = 0, now = 0, sum = 0, qaz = 0;
		For(i,1,k) {
			if(s&(1ll<<(i-1))) {
				For(j,1,n) ee[++qwe] = {i+n,j,a[i][j]}; 
				now ++;sum += a[i][0];
			}
		}
		For(i,1,tot) ee[++qwe] = g[i];
		sort(ee+1,ee+qwe+1);
		For(i,1,n+k) fa[i] = i;
		For(i,1,qwe) {
			intl fu = get(ee[i].u), fv = get(ee[i].v);
			if(fu != fv) sum += ee[i].w, fa[fu] = fv, qaz ++;
			if(qaz == n + now - 1) break;
		}
		ans = min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

