#include <bits/stdc++.h>
using namespace std;

struct node{
	int u,v,w;
	bool operator<(node &an){
		return w < an.w;
	}
};
node arr[1000010];
vector<int> v[12];
int n,m,k,fa[1000010],num;
long long ans;

int Find(int x){
	if(fa[x] != x) fa[x] = Find(fa[x]);
	return fa[x];
}

void Add(int x,int y){
	fa[x] = Find(y);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> arr[i].u >> arr[i].v >> arr[i].w;
	for(int i = 1,x;i <= k;i++){
		cin >> x;
		v[i][0] = x;
		for(int j = 1,y;j <= n;j++){
			cin >> y;
			v[i][j] = y;
		}
	}
	sort(arr + 1,arr + 1 + n);
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++){
		int u = arr[i].u,v = arr[i].v,w = arr[i].w;
		if(fa[u] == fa[v]) continue;
		for(int j = 1;j <= k;j++){
			w = min(w,v[j][u] + v[j][v]);
		}
		ans += w;
		num++;
		Add(u,v);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
