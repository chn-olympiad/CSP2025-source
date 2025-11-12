#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 5 , M = 1e6 + 5;
int n , m , k , fa[N] , cnt;
ll c[15] , a[15][N];
ll sum;
struct node{
	int u , v;
	ll w;
	bool operator<(const node &a)const{
		return w < a.w;
	}
}d[M];
map<pair<int , int> , ll>mp;
int find(int x){
	if(x == fa[x])return x;
	return fa[x] = find(fa[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> d[i].u >> d[i].v >> d[i].w;
		if(!mp.count({d[i].u , d[i].v}))mp[{d[i].u , d[i].v}] = d[i].w;
		else mp[{d[i].u , d[i].v}] = min(mp[{d[i].u , d[i].v}] , d[i].w);
		mp[{d[i].v , d[i].u}] = mp[{d[i].u , d[i].v}];
	}
	bool flag = false;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i])flag = true;
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j])flag = true;
		}
	}
	if(!flag){
		cout << 0;
		return 0;
	}
	if(k == 0){
		sort(d + 1 , d + m + 1);
		for(int i = 1;i <= n;i++)fa[i] = i;
		for(int i = 1;i <= m;i++){
			int fx = find(d[i].u) , fy = find(d[i].v);
			if(fx == fy)continue;
			fa[fy] = fx;
			cnt++;
			sum += d[i].w;
			if(cnt == n - 1){
				cout << sum;
				return 0;
			}
		}
		return 0;
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			for(int l = j + 1;l <= n;l++){
				if(!mp.count({j , l}))mp[{j , l}] = a[i][j] + a[i][l] + c[i];
				else mp[{j , l}] = min(mp[{j , l}] , a[i][j] + a[i][l] + c[i]);
				mp[{l , j}] = mp[{j , l}];
			}
		}
	}
	int tot = 0;
	for(int j = 1;j <= n;j++){
		for(int l = j + 1;l <= n;l++){
			d[++tot] = {j , l , mp[{j , l}]};
		}
	}
	sort(d + 1 , d + tot + 1);
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= tot;i++){
		int fx = find(d[i].u) , fy = find(d[i].v);
		if(fx == fy)continue;
		fa[fy] = fx;
		cnt++;
		sum += d[i].w;
		if(cnt == n - 1){
			cout << sum;
			return 0;
		}
	}
	return 0;
}
