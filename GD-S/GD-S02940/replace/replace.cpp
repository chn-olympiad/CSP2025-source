#include<bits/stdc++.h>
using namespace std;
int n,q,h1,h2,h3,h4,hsh[5000009],hshcnt,hsh2[5000009],hshcnt2;
struct frt{
	int a,b,c,d,e,f;
	frt(int _a = 0,int _b = 0,int _c = 0,int _d = 0,int _e = 0,int _f = 0):
		a(_a),b(_b),c(_c),d(_d),e(_e),f(_f)
	{}
	bool operator<(const frt &fb)const{
		if(a != fb.a)
			return a < fb.a;
		if(b != fb.b)
			return b < fb.b;
		if(c != fb.c)
			return b < fb.c;
		if(d != fb.d)
			return d < fb.d;
		return false;
	}
}dt[200009];
mt19937 rp(chrono :: steady_clock :: now().time_since_epoch().count());
const int mod = 999911659,base = rp() % 999911633 + 26;
char s1[5000009],s2[5000009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i = 1; i <= n; i ++){
		scanf(" %s %s",s1,s2);
		int o = strlen(s1);
		int l = 0;
		while(l < o && s1[l] == s2[l])
			l ++;
		int p = o;
		while(p > 0 && s1[p - 1] == s2[p - 1])
			p --;
		if(p < l)
			continue;
		h1 = h2 = h3 = h4 = 0;
		for(int j = l; j < p; j ++){
			h1 = (1ll * h1 * base % mod + s1[j] - 'a') % mod;
			h2 = (1ll * h2 * base % mod + s2[j] - 'a') % mod; 
		}
		for(int j = l - 1; j >= 0; j --){
			h3 = (1ll * h3 * base % mod + s1[j] - 'a') % mod;
		}
		for(int j = p; j < o; j ++){
			h4 = (1ll * h4 * base % mod + s1[j] - 'a') % mod;
		}
		dt[i] = frt(h1,h2,h3,h4,l,o - p);
	}
	sort(dt + 1,dt + n + 1);
	for(int i = 1; i <= q; i ++){
		scanf(" %s %s",s1,s2);
		unsigned long long o = strlen(s1);
		if(strlen(s2) != o){
			puts("0");
			continue;
		}
		h1 = h2 = h3 = h4 = 0;
		unsigned long long l = 0;
		while(l < o && s1[l] == s2[l])
			l ++;
		unsigned long long p = o;
		while(p > 0 && s1[p - 1] == s2[p - 1])
			p --;
		for(unsigned long long j = l; j < p; j ++){
			h1 = (1ll * h1 * base % mod + s1[j] - 'a') % mod;
			h2 = (1ll * h2 * base % mod + s2[j] - 'a') % mod;
		}
		hshcnt = 0;
		for(unsigned long long j = p; j < o; j ++){
			hshcnt ++;
			hsh[hshcnt] = (1ll * hsh[hshcnt - 1] * base % mod + s1[j] - 'a') % mod;
		}
		hshcnt2 = 0;
		for(unsigned long long j = l - 1; j < l; j --){
			hshcnt2 ++;
			hsh2[hshcnt2] = (1ll * hsh2[hshcnt2 - 1] * base % mod + s1[j] - 'a') % mod; 
		}
		int so = lower_bound(dt + 1,dt + n + 1,frt(h1,h2,0,0,0,0)) - dt;
		int ans = 0;
		while(dt[so].a == h1 && dt[so].b == h2){
			if(dt[so].e <= hshcnt2 && dt[so].c == hsh2[dt[so].e] && dt[so].f <= hshcnt && dt[so].d == hsh[dt[so].f])
				ans ++;
			so ++;
		}
		printf("%d\n",ans);
	}
}
