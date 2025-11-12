#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr)
#define ll long long
#define N 10004
#define K 11
#define M 1000006

struct node {
	int u,v;
	ll w;
} e[M],h[N * K];

int n,m,k;
ll c[K];
int fa[N + K];
int siz[N + K];

int gf(int x){
	if(x == fa[x]){
		return x;
	}
	fa[x] = gf(fa[x]);
	return fa[x];
}

void mf(int x,int y){
	x = gf(x);
	y = gf(y);
	if(x != y){
  		if(siz[x] > siz[y]){
			fa[y] = x;
			siz[x] += siz[y];
		}else{
			fa[x] = y;
			siz[y] += siz[x];
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	IOS;
	std::cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		std::cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int cnt = 0;
	for(int i = 1;i <= k;i++){
		std::cin >> c[i];
		for(int j = 1;j <= n;j++){
			cnt++;
			h[cnt].u = i + n;
			h[cnt].v = j;
			std::cin >> h[cnt].w;
		}
	}
	std::sort(e + 1,e + m + 1,[](node x,node y){
		return x.w < y.w;
	});
	std::sort(h + 1,h + cnt + 1,[](node x,node y){
		return x.w < y.w;
	});
	ll ans = 0x7fffffffffffffff;
	for(int l = 0;l < (1 << k);l++){
		for(int i = 1;i <= n + k;i++){
			fa[i] = i;
			siz[i] = 1;
		}
		ll sum = 0;
		int r = 0;
		for(int o = 0;o < k;o++){
			if(l & (1 << o)){
				sum += c[o + 1];
				r++;
			}
		}
//		std::cout << r << " " << cnt << '\n';
		int i = 1,j = 1;
		int cn = 0;
		while(cn < n + r - 1 && (i <= m || j <= cnt)){
			while(j <= cnt && (l & (1 << (h[j].u - n - 1))) == 0) j++;
//			std::cout << "cmp:" << i << " " << j << " " << h[j].w << " " << e[i].w << '\n';
			if(j <= cnt && (h[j].w < e[i].w || i > m)){
				int tu = gf(h[j].u);
				int tv = gf(h[j].v);
				if(tu != tv){
					cn++;
					sum += h[j].w;
					mf(tu,tv);
//					std::cout << "h:" << j << " " << h[j].u << " " << h[j].v << " " << h[j].w << '\n';
				}
				j++;
			}else if(i <= m){
				int tu = gf(e[i].u);
				int tv = gf(e[i].v);
				if(tu != tv){
					cn++;
					sum += e[i].w;
					mf(tu,tv);
//					std::cout << "e:" << i << " " << e[i].u << " " << e[i].v << " " << e[i].w << '\n';
				}
				i++;
			}
		}
		if(cn == n + r - 1){
			ans = std::min(ans,sum);
		}
	}
	std::cout << ans;
	return 0;
}

