#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10,inf = 0x3f3f3f3f;
int n,midn,ans,T;
int tab[maxn][4],root;
int f[410][410];

struct str{
	int l,r,f;
}help[maxn];
int cnt;
int www[maxn];
str mk(int a,int b,int c){
	str ret;
	ret.l = a,ret.r = b,ret.f = c;
	return ret;
}
void solve1(){
	midn = n>>1,ans = -inf,root = 0;
	for(int i = 1;i <= n;i ++){
		cin >> tab[i][1] >> tab[i][2] >> tab[i][3];
		root += tab[i][3];
		tab[i][1] -= tab[i][3];
		tab[i][2] -= tab[i][3];
	}
	for(int i = 1;i <= n;i ++)
	for(int j = 1;j <= n;j ++) f[i][j] = -inf;
	
	for(int i = 1,l,r;i <= n;i ++){
		
		cnt = 0;
		for(l = i;l >= 0;l --){
			for(r = i;r >= 0;r --){
				if(l == 0&&r == 0) continue;
				if(l+r > i) continue;
				if(l) help[++cnt] = mk(l,r,f[l-1][r]+tab[i][1]);
				if(r) help[++cnt] = mk(l,r,f[l][r-1]+tab[i][2]);
			}
		}
		for(int j = 1;j <= cnt;j ++){
			l = help[j].l;
			r = help[j].r;
			f[l][r] = max(f[l][r],help[j].f);
		}
	}
	for(int l = 0;l <= n;l ++)
	for(int r = 0,p;r <= n-l;r ++){
		p = n-l-r;
		if(l <= midn && r <= midn && p <= midn)
		ans = max(ans,f[l][r]);
	}
	cout << ans+root <<'\n';
}
bool cmp(int x,int y){
	return x>y;
}
void solve2(){
	ans = root = 0;
	for(int i = 1;i <= n;i ++){
		cin >> tab[i][1] >> tab[i][2] >> tab[i][3];
		tab[i][2] -= tab[i][1],tab[i][2] -= tab[i][1];
		root += tab[i][1];
		www[i] = tab[i][2];
	}
	sort(www+1,www+1+n,cmp);
	for(int i = 1;i <= (n/2);i ++){
		ans += www[i];
	}
	cout << ans+root;
}
int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin >> T;
	while(T --){
		cin >> n;
		if(n <= 200){
			solve1();
		}else{
			solve2();
		}
	}
	return 0;
}
/*

3

4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0




1
4
0 1 0

0 1 0

0 2 0

0 2 0

*/
