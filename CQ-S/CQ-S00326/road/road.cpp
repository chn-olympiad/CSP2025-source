#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long int L;
L n,m,k,f[15015],c,x[65],t,s,l,z;
struct e{
	L u,v,w,d;
};
e r[1150005];
bool o(e p,e q){return p.w < q.w;}
L g(L y){
	if(f[y] == y){return y;}
	f[y] = g(f[y]);
	return f[y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	c = m;
	for(L i = 1LL;i <= m;i++){
		scanf("%lld %lld %lld",&r[i].u,&r[i].v,&r[i].w);
		r[i].d = 0LL;
	}
	for(L i = 1LL;i <= k;i++){
		scanf("%lld",&x[i]);
		for(L j = 1LL;j <= n;j++){
			scanf("%lld",&t);
			c++;
			r[c].u = i + n;
			r[c].v = j;
			r[c].w = t;
			r[c].d = i;
		}
	}
	sort(r + 1LL,r + c + 1LL,o);
	l = 9999999999999999LL;
	for(L i = 0LL;i < (1LL << k);i++){
		s = 0LL;
		z = n;
		for(L j = 1LL;j <= k;j++){
			if(i & (1LL << (j - 1LL))){
				s += x[j];
				z++;
			}
		}
		for(L j = 1LL;j <= n + k;j++){f[j] = j;}
		for(L j = 1LL;j <= c;j++){
			if(g(r[j].u) == g(r[j].v) || (r[j].d != 0LL && (i & (1LL << (r[j].d - 1LL))) == 0LL)){continue;}
			f[f[r[j].u]] = f[r[j].v];
			s += r[j].w;
			z--;
			if(z <= 1LL){break;}
		}
		if(s < l){l = s;}
	}
	printf("%lld",l);
	return 0;
}
