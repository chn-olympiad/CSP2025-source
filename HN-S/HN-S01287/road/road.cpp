#include<bits/stdc++.h>
using namespace std;
int n,m,k,len;
int mm;
long long minn = 1e18;
struct pi{
	long long u,v,w,id;
}s[1000005],sf[1000005];
int a[15][10005];
bool vis[10011];
int fa[10011];
bool cmp(pi x,pi y){
	return x.w < y.w;
}
bool cmp1(pi x,pi y){
	return x.id < y.id;
}
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void check(){
	for(int i = 1 ; i <= n + k ; i ++)fa[i] = i;
	long long ans = 0;
	len = 0;
	int ll = 0;
//	for(int i = 1 ; i <= m ; i ++){
//		s[i].u = sf[i].u;
//		s[i].v = sf[i].v;
//		s[i].w = sf[i].w;
//	}
	for(int i = 1 ; i <= k ; i ++){
		if(!vis[i])continue;
		ans += a[i][0];
		ll ++;
		for(int j = 1 ; j <= n ; j ++){
			len ++;
			s[m + len].u = i + n;
			s[m + len].v = j;
			s[m + len].w = a[i][j];
			s[m + len].id = n + 11;
		}
	}
	sort(s + 1 , s + 1 + m + len , cmp);
//	if(!vis[1] && !vis[2])cout << s[1].w << "\n";
	int cnt = 0;
	for(int i = 1 ; i <= m + len ; i ++){
		if(find(s[i].u) == find(s[i].v)){
			continue;
		}
		cnt ++;
		int u = find(s[i].u),v = find(s[i].v);
		fa[u] = v;
		ans += s[i].w; 
//		if(vis[1] && !vis[2]){
//			cout << len << " " << s[i].u << " " << s[i].v << " " << s[i].w << "\n";
//		}
		if(cnt == n + ll - 1)break;
	}
	minn = min(minn , ans);
//	if(ans == 12){
//		cout << vis[1] << " " << vis[2] << "\n";
//	}
	sort(s + 1 , s + 1 + m + len , cmp1);
	return;
}
void dfs(int cur){
	if(cur == k + 1){
		check();
		return;
	}
	vis[cur] = 1;
	dfs(cur + 1);
	vis[cur] = 0;
	dfs(cur + 1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++){
		cin >> s[i].u >> s[i].v >> s[i].w;
//		s[i].u = sf[i].u;
//		s[i].v = sf[i].v;
//		s[i].w = sf[i].w;
		s[i].id = i;
	}
	for(int i = 1 ; i <= k ; i ++){
		cin >> a[i][0];
		vis[i] = 0;
		for(int j = 1 ; j <= n ; j ++){
			cin >> a[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		fa[i] = i;
	} 
	sort(s + 1 , s + 1 + m , cmp);
//	if(!vis[1] && !vis[2])cout << s[1].w << "\n";
	int cnt = 0;
	long long ans = 0;
	for(int i = 1 ; i <= m ; i ++){
		int u = find(s[i].u),v = find(s[i].v);
		if(u == v){
			continue;
		}
		fa[u] = v;
		sf[++mm].u = s[i].u;
		sf[mm].v = s[i].v;
		sf[mm].w = s[i].w;
		cnt ++;
		ans += s[i].w; 
//		if(vis[1] == 0 && !vis[2]){
//			cout << cnt <<" " << s[i].u << " " << s[i].v << " " << s[i].w << "\n";
//		}
		if(cnt == n - 1)break;
	}
	for(int i = 1 ; i <= mm ; i ++){
		s[i].u = sf[i].u;
		s[i].v = sf[i].v;
		s[i].w = sf[i].w;
//		cout << s[i].w << " ";
		s[i].id = i;
	}
	m = mm;
	minn = min(minn , ans);
//	cout << minn << " " << cnt << "\n";
	dfs(1);
	cout << minn;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

6 7 0
1 3 5
1 2 3
2 5 1
3 4 3
4 5 3
3 6 1
6 5 4
*/
