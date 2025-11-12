#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
struct road{
	int u,v,w;
};
int n,m,k;
road a[N];
int fa[N];
int city_size[15];
int new_city[15][N];
bool cmp(road x, road y){
	return x.w < y.w;
}
int getf(int x){
	if(fa[x] != x){
		fa[x] = getf(fa[x]);
	}
	return fa[x];
}
int dij(){
	int sum = 0;
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1; i <= m; i++){
		int t = a[i].u;
		int t1 = a[i].v;
		t = getf(t);
		t1 = getf(t1);
		if(t != t1){
			sum += a[i].w;
			fa[t] = t1;
		}
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 1; i <= m; i++){
		scanf("%lld%lld%lld",&a[i].u, &a[i].v, &a[i].w);
	}
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	bool flag = false;
	for(int i = 1; i <= k; i++){
		scanf("%lld",&city_size[i]);
		flag = false;
		if(city_size[i] != 0){
			flag = true;
		}
		for(int j = 1; j <= n; j++){
			scanf("%lld",&new_city[i][j]);
			if(new_city[i][j] != 0){
				flag = true;
			}
		}
		if(flag == false){
			printf("0\n");
			return 0;
		}
	}
	if(k == 0){
		printf("%lld",dij());
		return 0;
	}
	int t = dij();
	printf("%lld",t);
	return 0;
}

