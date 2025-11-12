#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define fo(i,j,k,l) for(int i = j;i <= k;i += l)
#define lowbit(x) (x & -x)
using namespace std;
int n,m,k;
int c[15];
struct edge {
	int u,v,w;
}e[2000005],e2[20505],e3[20505];
int cnt;
bool cmp(edge x,edge y) {
	return x.w < y.w;
}
int fa[20505];
int find(int x) {
	if(fa[x] == x)return x;
	else return fa[x] = find(fa[x]);
}
int now;
int ans;
int tot[15];
int bz[15];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&k);
	fo(i,1,m,1) {
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[i].u = u,e[i].v = v,e[i].w = w;
	}
	sort(e + 1,e + 1 + m,cmp);
	fo(i,1,n,1)fa[i] = i;
	fo(i,1,m,1) {
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if(find(u) == find(v))continue;
		e2[++ cnt] = e[i];
		now += w;
		fa[find(u)] = find(v); 
	}
	int lst;
	fo(i,1,cnt,1) {
		e[i] = e2[i];
	}
	lst = cnt;
	cnt = 0;
	ans = now;
	//cout << now << endl;
	fo(i,1,k,1) {
		scanf("%lld",&c[i]);
		//cout << c[i] << endl;
		//if(i <= 5)cout << c[i] << endl; 
		fo(j,1,n,1) {
			int w;
			scanf("%lld",&w);
			e3[j].u = n + i,e3[j].v = j,e3[j].w = w;
		}
		sort(e3 + 1,e3 + 1 + n,cmp);
		int i1 = 1,i2 = 1;
		fo(j,1,n + k,1)fa[j] = j;
		//int tot = 0;
		while(i1 <= lst && i2 <= n) {
			if(e[i1].w <= e3[i2].w) {
				int u = e[i1].u,v = e[i1].v,w = e[i1].w;
				if(find(u) == find(v)) {
					i1 ++;
					continue;
				}
				e2[++ cnt] = e[i1];
				fa[find(u)] = find(v);
				i1 ++;
			}
			else {
				int u = e3[i2].u,v = e3[i2].v,w = e3[i2].w;
				if(find(u) == find(v)) {
					i2 ++;
					continue;
				}
				e2[++ cnt] = e3[i2];
				fa[find(u)] = find(v);
				i2 ++;
				//tot ++;
			}
		}
		while(i1 <= lst) {
			int u = e[i1].u,v = e[i1].v,w = e[i1].w;
			if(find(u) == find(v)) {
				i1 ++;
				continue;
			}
			e2[++ cnt] = e[i1];
			fa[find(u)] = find(v);
			i1 ++;
		}
		while(i2 <= n) {
			int u = e3[i2].u,v = e3[i2].v,w = e3[i2].w;
			if(find(u) == find(v)) {
				i2 ++;
				continue;
			}
			e2[++ cnt] = e3[i2];
			fa[find(u)] = find(v);
			i2 ++;
			//tot ++;
		}
		fo(j,1,k,1)tot[j] = bz[j] = 0;
		now = 0;
		fo(j,1,cnt,1) {
			if(e2[j].u > n)tot[e2[j].u - n] ++;
		}
		//fo(j,1,k,1)cout << tot[j] << ' ';
		//cout << endl;
		fo(j,1,cnt,1) {
			if(e2[j].u > n) {
				if(tot[e2[j].u - n] > 1) {
					now += e2[j].w;
					if(bz[e2[j].u - n] == 0)now += c[e2[j].u - n];
					bz[e2[j].u - n] = 1;
				}
			}
			else now += e2[j].w;
		}
		if(now < ans) {
			ans = now;
			fo(j,1,cnt,1)e[j] = e2[j];
			lst = cnt;
		}
		//cout << ans << endl;
		//cout <<cnt << endl;
		cnt = 0;
		//cout << tot << endl;
		//cout << now << endl;
		//cout << lst << endl;
	}
	/*
	now = 0;
	fo(i,1,lst,1)now += e[i].w;
	now += c[1] + c[2] + c[3];
	cout << lst << endl;*/
	printf("%lld\n",ans);
	//cout << ans - 5182974424;
	return 0;
}

