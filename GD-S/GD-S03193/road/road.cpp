#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct rd{
	int u,v,w;
}lu[2000010];
int a[20][10010];
int c[20];
bool cmp(rd a,rd b){
	return a.w <= b.w;
}
int fa[100010];
int lt;
int fi(int x){
	if(fa[x] == x)return x;
	return fa[x] = fi(fa[x]); 
}
int ans;
void ti(int x,int y,int w){
	int a = fi(x),b = fi(y);
	if(fa[a]!=fa[b]){
		fa[a] = fa[b];
		ans += w;
		lt++;
	}
}
signed main (){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int su = 0;
	for (int i = 1 ; i <= n ; i ++){
		fa[i] = i;
	}
	for (int i = 1 ; i <= m ; i ++){
		cin >> lu[i].u >> lu[i].v >> lu[i].w;
	}
	su = m;
	for (int i = 1 ; i <= k ; i ++){
		su = m;
		cin >> c[i];
		for(int j = 1 ; j <= n ; j ++){
			cin >> a[i][j];
		}
		for (int x = 1 ; x <= n ; x ++){
			for (int y = x+1 ; y <= n ; y ++){
				su++;
				if(i==1){
					lu[su] = {x,y,a[i][x]+a[i][y]};
				}else if(lu[su].w>a[i][x]+a[i][y]){
					lu[su] = {x,y,a[i][x]+a[i][y]};
				}
			}
		}
	}
	sort(lu+1,lu+su+1,cmp);
	int i = 1;
	while(lt<n-1){
		ti(lu[i].u,lu[i].v,lu[i].w);
		i++;
	}
	cout << ans << endl;
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/
