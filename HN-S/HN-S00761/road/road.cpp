#include <bits/stdc++.h>
using namespace std;
#define int long long
struct st{
	int u,v,w;
}a[1000001];
int fa[1000001];
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
bool cmp(st x,st y){
	return x.w < y.w;
}
int s[11][100001];
int c[11];
int vis[101];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n>> m>>k;	
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i].u>>a[i].v>>a[i].w;
	}
	sort(a + 1,a + m + 1,cmp);
	int f = 1;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i] != 0)f = 0;
		for(int j = 1;j <= n;j++){
			cin >> s[i][j];
			if(s[i][j] != 0)f = 0;
		}
	}
	if(k == 0){
		int cnt = 0;
		int ans = 0;
		for(int i = 1;i <= m;i++){
			int x = find(a[i].u),y = find(a[i].v);
			if(x != y){
				fa[x] = y;
				ans += a[i].w;
				cnt++;
			}
			if(cnt == n - 1)break;
		}
		cout<< ans;
	}else if(f){
		cout << 0;
	}else{
		int cnt = 0;
		int ans = 0;
		int sum = m;
		for(int i = 1;i <= m;i++){
			int x = find(a[i].u),y = find(a[i].v);
			if(x != y){
				fa[x] = y;
				int l = k + 1;
				for(int j = 1;j <= k;j++){
					if(a[i].w > s[j][a[i].u] + s[j][a[i].v] + c[j]){
						a[i].w = s[j][a[i].u] + s[j][a[i].v] + c[j];
						l = j;
					}
				}
				ans += a[i].w;
				c[l] = 0;
				cnt++;
			}
			if(cnt == n - 1)break;
		}
		sort(a + 1,a + sum + 1,cmp);
		cnt = 0;
		ans = 0;
		for(int i = 1;i <= n;i++)fa[i] = i;
		for(int i = 1;i <= m;i++){
			int x = find(a[i].u),y = find(a[i].v);
			if(x != y){
				fa[x] = y;
				int u = 0;
				ans += a[i].w;
				cnt++;
			}
			if(cnt == n - 1)break;
		}
		cout << ans;
	}
	return 0;
}
