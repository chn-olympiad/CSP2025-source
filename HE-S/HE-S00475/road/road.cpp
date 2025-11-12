#include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long ans;

struct city{
	int c;
	int a[10005];
}citys[13];
struct road{
	int u,v,w;
}roads[1000006];

bool cmp(road a,road b){
	return a.w < b.w;
}

bool vis[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i<=m;i++){
		cin >> roads[i].u >> roads[i].v >> roads[i].w;
	}
	for (int i = 1;i<=k;i++){
		cin >> citys[i].c;
		for (int j = 1;j<=n;j++){
			cin >> citys[i].a[i];
		}
	}
	if (k==0){
		sort(roads+1,roads+1+m,cmp);
		int cnt = 0;
		for (int i = 1;cnt < n-1;i++){
			if (!vis[roads[i].u] || !vis[roads[i].v]){
				cnt++;
				cout << roads[i].u << "->" << roads[i].v << " " << roads[i].w << endl;
				ans += roads[i].w;
				cout << ans << endl;
				vis[roads[i].u] = true;
			}
		}
		cout << ans;
		return 0;
	}
	
	return 0;
}
