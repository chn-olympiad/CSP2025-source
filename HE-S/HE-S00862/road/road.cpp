#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
//#define int long long
const int K = 11;
const int N = 1e6+20;
int n,m,k;
struct line{
	long long u,v,c;
};
bool cmp(line a,line b){
	return a.c < b.c;
}
vector<line>g;
int c[K];
int a[K][N];
int f[N];
int fnd(int x){
	if (f[x] == x) return x;
	return f[x] = fnd(f[x]);
}
void merge(long long x,long long y){
	if (fnd(x) == fnd(y)) return;
	f[fnd(x)] = f[y];
}
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans = 0x3f3f3f3f3f3f3f3f;
	cin >> n >> m >> k;
	rep(i,1,m){
		line l;
		scanf("%lld %lld %lld",&l.u ,&l.v,&l.c);
		g.push_back(l);
	}
	// ³ÇÕò£ºn+1~n+k
	rep(i,1,k){
		cin >> c[i];
		rep(j,1,n) cin >> a[i][j];
	} 
	vector<line>rg;
	rep(status,0,(1<<k) - 1){
		long long cnt = 0;
		rg = g;
		rep(i,1,n+k) f[i] = i;
		rep(i,1,k){
			if (status >> (i-1) & 1){
				cnt += c[i];
				rep(j,1,n){
					line l;
					l.u = i + n;
					l.v = j;
					l.c = a[i][j];
					rg.push_back(l);
				}
			}
		}
		sort(rg.begin(),rg.end(),cmp);
		for(line l:rg){
//			prlong longf("bcj : %d %d\n",fnd(l.u),fnd(l.v));
			if (fnd(l.u) != fnd(l.v)){
//				prlong longf("link %d %d %d\n",l.u,l.v,l.c);
				cnt += l.c;
				merge(l.u,l.v);
			}
		}
		ans = min(ans,cnt);
	}
	cout << ans;
	return 0;
}

