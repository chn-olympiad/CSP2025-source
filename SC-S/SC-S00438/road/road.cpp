#include<bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 10;
const long long M = 1e6 + 10;
const long long K = 15;
long long f[N];
long long record[N];
long long a[K][N];
inline void read(long long &x){
	x = 0;
	bool f = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		f = (c == '-');
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	if(f) x = -x;
}
inline long long find(long long x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
struct node{
	long long u , v , w;
}e[N * K + M];
inline bool cmd(node a , node b){
	return a.w < b.w;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	long long n , m , k;
	cin >> n >> m >> k;
	for(long long i = 1;i <= n;++ i) f[i] = i;
	long long cnt = 0;
	for(long long i = 1;i <= m;++ i){
		long long u , v , w;
		read(u) , read(v) , read(w);
		e[++ cnt].u = u;
		e[cnt].v = v;
		e[cnt].w = w;
	}
	for(long long i = 1;i <= k;++ i){
		long long c;
		read(c);
		for(long long j = 1;j <= n;++ j){
			read(a[i][j]);
			if(!a[i][j])
			record[i] = j;
		}
		if(record[i]){
			for(long long j = 1;j <= n;++ j){
				if(record[i] != j){
					e[++ cnt].u = record[i];
					e[cnt].v = j;
					e[cnt].w = a[i][j];
				}
			}
		}
	}
	sort(e + 1 , e + 1 + cnt , cmd);
	long long ans = 0;
	long long bit = 0;
	for(long long i = 1;i <= cnt;++ i){
		long long u = find(e[i].u) , v = find(e[i].v);
		if(u != v){
			++ bit;
			f[u] = v;
			ans += e[i].w;
			if(bit == n - 1){
				cout << ans;
				break;
			}
		}
	}
	return 0;
} 
//4 5 0
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 2 3