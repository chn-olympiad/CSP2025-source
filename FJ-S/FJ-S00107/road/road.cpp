#include <bits/stdc++.h>
using namespace std;
inline int read(){// no minus
	int r = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while('0' <= c && c <= '9') r = (r << 3) + (r << 1) + (c ^ '0'),c = getchar(); 
	return r;
}
struct e{
	int x,y,w;
	inline friend bool operator<(const e&x,const e&y){
		return x.w < y.w;
	}
} wk[2000005],cb[1024][10025],kw[12][10025];
int cnt,nt;
int fa[10025];
bool v[15],v2[15];
int c[15];
long long sm[1024];
int Lg[1024],Pc[1024];
int fd(int x){
	return x == fa[x] ? x : fa[x] = fd(fa[x]);
}
int n,m,k;
inline long long kr(e*b){
	long long res = 0;
	for(int i = 1;i <= n + k;i++) fa[i] = i;
	nt = 0;
	for(int i = 1;i <= cnt;i++){
		int x = fd(wk[i].x),y = fd(wk[i].y);
		if(x ^ y){
			fa[x] = y;
			res += wk[i].w;
			b[++nt] = wk[i];
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();m = read();k = read();
	for(int i = 1;i <= m;i++){
		wk[i].x = read();
		wk[i].y = read();
		wk[i].w = read();
	}
	cnt = m;
	sort(wk + 1,wk + cnt + 1);
	long long ans = kr(cb[0]);
	//printf("%lld\n",ans);
	for(int i = 0;i < k;i++){
		//int lsnt = cnt;
		//int c;
		c[i] = read();
		for(int j = 1;j <= n;j++) kw[i][j].w = read(),kw[i][j].x = n + 1 + i,kw[i][j].y = j;
		sort(kw[i] + 1,kw[i] + n + 1);
	}
	Pc[1] = 1;
	for(int i = 2;i < 1024;i++) Lg[i] = Lg[i >> 1] + 1,Pc[i] = Pc[i >> 1] + (i & 1);
	for(int i = 1;i < (1 << k);i++){
		int zd = Lg[i & -i];
		//printf("%d\n",zd);
		int o = i ^ (1 << zd);
		int bs = Pc[o] + n - 1;
		sm[i] = sm[o] + c[zd];
		int p1 = 1,p2 = 1;
		cnt = 0;
		while(p1 <= bs && p2 <= n){
			if(cb[o][p1] < kw[zd][p2]) wk[++cnt] = cb[o][p1++];
			else wk[++cnt] = kw[zd][p2++];
		}
		while(p1 <= bs) wk[++cnt] = cb[o][p1++];
		while(p2 <= n) wk[++cnt] = kw[zd][p2++];
		ans = min(ans,kr(cb[i]) + sm[i]);
		//printf("%d %lld\n",i,dp);
	}
	printf("%lld",ans);
	return 0;
} 
