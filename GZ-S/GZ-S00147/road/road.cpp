//GZ_S00147 贵阳中天中学 廖颢云 
#include <bits/stdc++.h>
using namespace std;
int n,t,m,k,fa[100005],cnt,sumn;
struct node1{
	int u,v,w;
}a[1000005];
struct node2{
	int y,u,v,w;
}b[1000005];
int find(int x){
	if(x == fa[x])return fa[x];
	return fa[x] = find(fa[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	cnt = n;
	for(int i = 1;i <= m;i++)cin >> a[i].u >> a[i].v >> a[i].w;
	for(int i = 1;i <= k;i++){
		cin >> b[i].y;
		for(int j = 1;j <= m;j++){
			cin >> b[j].w;
			b[j].u = i,b[j].v = j;
		}
	}
	sort(a+1,a+1+m);
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= m;i++){
		int u = a[i].u,v = a[i].v;
		if(find(u) != find(v))fa[u] = find(v);
		cnt--;
		if(b[i].w + b[i].y < a[i].w)sumn += b[i].w + b[i].y;
		else sumn += a[i].w;
		if(cnt == 1)break;
	}
	cout << sumn;
	return 0;
} 
