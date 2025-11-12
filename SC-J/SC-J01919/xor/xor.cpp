#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define rep(i, l, r) for(int i = (l), END##i = (r); i <= END##i; ++i)
#define per(i, r, l) for(int i = (r), END##i = (l); i >= END##i; --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fileI(x) freopen(x, "r", stdin)
#define fileO(x) freopen(x, "w", stdout)
#define ML debug("\n%.2lf MB\n", (&Med-&Mst)/1024.0/1024)
#define TL debug("\n%.2lf s\n", 1.0*clock()/CLOCKS_PER_SEC)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pq priority_queue
bool Mst;
const int N=5e5+5,V=1148576,INF=0x3f3f3f3f;
int n,k,a[N],f[N],M[V];
bool Med;
int main(){
	fileI("xor.in");
	fileO("xor.out");
//	ML;
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)a[i]^=a[i-1];
	rep(i,0,1048576)M[i]=-INF;
	f[0]=0,M[0]=0;
	rep(i,1,n){
		f[i]=max(M[a[i]^k]+1,f[i-1]);
		M[a[i]]=max(M[a[i]],f[i]);
	}
	printf("%d",f[n]);
//	TL;
	return 0;
}
