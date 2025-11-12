#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e6 + 6;
struct node{
	int u,v,w;
}a[N];
int n,m,fa[N],ans,cnt,k,v[N];
bool cmp(node x,node y){return x.w < y.w;};
int find(int x){return fa[x] == x?x:fa[x] = find(fa[x]);}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i ++)fa[i] = i;
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		cin >> u >> v >> w;
		a[i] = {u,v,w};
	}
	if(k == 0){
		sort(a + 1,a + 1 + m,cmp);
		for(int i = 1;i <= m;i ++){
			if(cnt == n - 1)break;
			int u = a[i].u,v = a[i].v,w = a[i].w;
			int fu = find(u),fv = find(v);
			if(fu == fv)continue;
			fa[fu] = fv;
			cnt ++;
			ans += w;
		}
		cout << ans;
	}else{
		int cnt = 0;bool f = 0;
		for(int i = 1;i <= k;i ++){
			int val;
			cin >> val;
			if(val == 0)cnt ++;
			for(int i = 1;i <= n;i ++){
				cin >> v[i];
				if(v[i] == 0)cnt ++;
			}
			if(cnt == n + 1)f = 1;
		}
		if(f){
			cout << 0;
			return 0;
		}
		sort(a + 1,a + 1 + m,cmp);
		for(int i = 1;i <= m;i ++){
			if(cnt == n - 1)break;
			int u = a[i].u,v = a[i].v,w = a[i].w;
			int fu = find(u),fv = find(v);
			if(fu == fv)continue;
			fa[fu] = fv;
			cnt ++;
			ans += w;
		}
		cout << ans;
	}
	return 0;
}

