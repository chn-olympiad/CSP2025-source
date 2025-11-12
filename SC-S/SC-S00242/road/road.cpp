#include<bits/stdc++.h>
#define int long long
//新年快乐！新年快乐，求求放过我这个鼠鼠吧。 
//求求了，ccf让我这个代码过吧!!求求了！！loveyou ccf 
using namespace std;
const int N = 1e4 + 20;
int n,m,k;
int b[11][N],c[N];
int fa[N];
bool us[11];
struct node{
	int u,v,w;
	int p = -1;
}a[1100000];
vector<node>v;
bool cmp(node a,node b){
	return a.w < b.w;
}
int find(int x){
	if(fa[x] == x){
		return x;
	}else{
		fa[x] = find(fa[x]);
		return fa[x];
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	n += k;
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n - k;j++){
			cin >> b[i][j];
			m++;
			a[m].p = i;
			a[m].u = n - k + i;
			a[m].v = j;
			a[m].w = b[i][j] + c[i];//权重不知道如何配，求求你了，ccf，让我过吧！ 
		}
	}
	sort(a + 1,a + m + 1,cmp);
	int x = 0;
	int ans = 0;
	int p = n - k;
	for(int i = 1;i <= m;i++){
		int fu = find(a[i].u),fv = find(a[i].v);
		if(fu == fv){
			continue;
		}else{
			fa[fv] = fu;
			x++;
			if(a[i].p == -1){
				ans += a[i].w;
			}else{
				if(us[a[i].p] == false){
					p++;
				}
				us[a[i].p] = true;
				ans += b[a[i].p][a[i].v];
			}
			if(x == p - 1){
				break;
			}
		}
	}
	for(int i = 1;i <= k;i++){
		ans += (us[i] ? c[i] : 0);
	}
	cout << ans;
	return 0;
}