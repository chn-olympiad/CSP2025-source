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
int n,cnt[20];
bool Med;
int main(){
	fileI("number.in");
	fileO("number.out");
	char ch=getchar();
	while('a'<=ch&&ch<='z'||'0'<=ch&&ch<='9'){
		if('0'<=ch&&ch<='9')cnt[ch-'0']++;
		ch=getchar();
	}
//	ML;
	per(i,9,0){
		rep(j,1,cnt[i]){
			putchar('0'+i);
		}
	}
//	TL;
	return 0;
}
