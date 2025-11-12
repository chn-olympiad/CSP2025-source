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
const int N=105;
int n,m,a[N];
bool Med;
int main(){
	fileI("seat.in");
	fileO("seat.out");
//	ML;
	scanf("%d%d",&n,&m);
	rep(i,1,n*m)scanf("%d",&a[i]);
	int b=a[1];
	sort(a+1,a+n*m+1,greater<>());
	rep(i,1,n*m)if(a[i]==b){
		int r=(i-1)/n+1,c=(i-1)%n+1;
		if(r&1)printf("%d %d",r,c);
		else printf("%d %d",r,n-c+1);
		break;
	}
//	TL;
	return 0;
}
