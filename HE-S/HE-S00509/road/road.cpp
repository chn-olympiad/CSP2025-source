#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,k;
struct road{
	int u;
	int v;
	int w;
}r[1000010];
struct _plus{
	int id;
	int pri[10010];
}p[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for (int i=1;i<=k;i++){
		cin >> p[i].id;
		for (int j=1;j<=n;j++){
			cin >> p[i].pri[j]; 
		}
	}
	for (int i=1;i<=k;i++){
		for (int j=1;j<=m;j++){
			if (r[j].u == i || r[j].v == i){
				r[j].w=0;
			}
		}
	}
	for (int i=1;i<=m;i++){
		ans+=r[i].w;
	}
	cout << ans;
	return 0;
}
