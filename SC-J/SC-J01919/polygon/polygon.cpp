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
const int N=5005,mod=998244353;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int n,a[N],f[N][N],pw[N],ans;
bool Med;
int main(){
	fileI("polygon.in");
	fileO("polygon.out");
//	ML;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,0,5000)f[0][i]=1;
	rep(i,1,n){
		per(j,5000,0){
			f[i][j]=f[i-1][j];
			if(j>=a[i])add(f[i][j],f[i-1][j-a[i]]);
		}
	}
	pw[0]=1;
	rep(i,1,n)pw[i]=pw[i-1]*2LL%mod;
	per(t,n,3){
		add(ans,(1LL*pw[t-1]-f[t-1][a[t]]+mod)%mod);
	}
	printf("%d",ans);
//	TL;
	return 0;
}