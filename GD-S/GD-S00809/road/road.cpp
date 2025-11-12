#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pdd;
typedef pair<int,pdd> pdp;
const int N = 5e5 + 31;

void read(int &x){
	x = 0; char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar();
	}
}

int n,m,k,f[N],a[19][N],c[N];
vector<pdp> e,ex;

int gf(int x){
	return f[x] == x ? x : f[x] = gf(f[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	read(n), read(m), read(k);
	for(int i = 1;i <= n + k;i++)	
		f[i] = i;
	for(int i = 1;i <= m;i++){
		int u,v,w; read(u), read(v), read(w);
		e.push_back(make_pair(w,pdd(u,v)));
	}
	for(int i = 0;i < k;i++){
		read(c[i]);
		for(int j = 1;j <= n;j++)
			read(a[i][j]);
	}
	sort(e.begin(),e.end());
	ll ans = 0;
	for(auto g : e){
		int w = g.first,u = g.second.first,v = g.second.second;
		if(gf(u) != gf(v)){
			ex.push_back(g);
			f[gf(u)] = v;
			ans += w;
		}
	}
	for(int i = 1;i < (1 << k);i++){
		ll tmp = 0; e = ex;
		for(int j = 1;j <= n + k;j++)	
			f[j] = j;
		for(int j = 0;j < k;j++) 
			if(i & (1 << j)){
				tmp += c[j];
				for(int l = 1;l <= n;l++)
					e.push_back(make_pair(a[j][l],pdd(n + j + 1,l)));
			}
		sort(e.begin(),e.end());
		for(auto g : e){
			int w = g.first,u = g.second.first,v = g.second.second;
			if(gf(u) != gf(v)){
				f[gf(u)] = v;
				tmp += w;
				if(tmp >= ans)
					break;
			}
		}
		ans = min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}
