#include<bits/stdc++.h>
#define int long long
#define f(i , l , r) for(int i = l;i <= r;i ++)
#define d(i , l , r) for(int i = r;i >= l;i --)
#define lowbit(x) ((x)&-(x))
#define pii pair<int,int>
#define fi first 
#define sc second
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N = 1e5 + 10 , M = 1e6 + 10;
int n , m , h , k , a[10][N];
struct edge{
	int u , v , w;
}e[M] , st[M];
bool cmp(edge a,edge b){
	return a.w < b.w;
}
int sz[N] , s[N];
int get_set(int u){
	return s[u] = (s[u] == u ? u : get_set(s[u]));
}
bool merge(int u,int v){
	u = get_set(u) , v = get_set(v);
	if(sz[u] > sz[v])swap(u , v);
	if(u != v)return s[u] = v , true;
	return false;
}
int krsk(int n, int op){
	sort(e + 1 , e + 1 + m , cmp);
	int ans = 0;h = 0;
	f(i , 1 , n)s[i]  =i , sz[i] = 1;
	f(i , 1 , m){
		int u = e[i].u , v = e[i].v , w = e[i].w;
		if(merge(u , v)){
//			cout << u << " " << v << "\n";
			if(op == 0)st[++h] = e[i];
			ans += w;
		}
	}
	return ans;
}
signed main(){
	fre("road");
	cin >> n >> m >> k;
	f(i  ,1 , m){
		int u , v , w;
		cin>> u >> v >> w;
		e[i] = {u , v , w};
	}
	f(i , 0 , k - 1){
		f(j , 0 , n)cin >> a[i][j];
	}
	krsk(n , 0);
	f(i , 1 , h)e[i] = st[i];m = n - 1;
	int ans = 1e18;
	f(s , 0 , (1 << k) - 1){
		int res = 0 , now = n;
		f(i , 0 , k - 1){
			if((s >> i) & 1){
				now ++;
				f(j , 1 , n)e[++m] = {now , j , a[i][j]};
				res += a[i][0];
			}
		}
//		cout << krsk(now , 1) << "\n";
		ans = min(ans , res + krsk(now , 1));
		f(i , 1 , n - 1)e[i] = st[i];m = n - 1;
	}
	cout << ans << "\n";
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
