#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u[10010], v[10010], w[10010];
int r[15][10010], c[15];
int vis[10010];//是否连通 
priority_queue<pair<long long, int> > d;//距离 
int ad[15];//是否共同富裕 
long long ans=0, num;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int flag=-1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	}
	ans=-1;
	for(int i=1;i<=k;i++){
		scanf("%d", &c[i]);
		num=c[i];
		if(c[i]!=0)flag=1;
		for(int j=1;j<=n;j++){
			scanf("%d", &r[i][j]);
			num+=r[i][j];
			if(r[i][j]!=0){
				flag=1;
			}
		}
		if(ans==-1){
			ans=num;
		}else{
			ans=min(ans, num);
		}
	}
	if(flag==-1){
		cout<<"0";
		return 0;
	}
	printf("%lld\n", ans);
	return 0;
}
