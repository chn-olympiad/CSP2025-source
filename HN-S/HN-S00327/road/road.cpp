#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,k;
struct node{
	int u,v,w;
	bool operator < (const node &b){
		return b.w > w; 
	}
}a[N];
int fa[N];
int c[N];
int b[30][N];
int vis[N];
int cnt = 0,res=0;
int find(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}
void bing(int x,int y,int i){
	x = find(x);
	y = find(y);
	if(x != y){
		cnt++;
		fa[x] = y;
		res+=a[i].w;
	}
	return ;
}
void work(){
	cin >>n >> m >>  k;
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> b[i][j];
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++){
		fa[i] = i;
	}
	for(int i=1;i<=m;i++){
		if(cnt == n-1){
			break;
		}
		bing(a[i].u,a[i].v,i);
	}
	cout << res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	work();
	return 0;
}

