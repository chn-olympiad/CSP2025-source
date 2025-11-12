#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c[200005],tot,tmp[200005],fa[200005];
long long dis[10005][1005];
bool flag[200005];
struct node{
	int x,y,vid;
	long long t;
	bool isv;
};
node a[50000005];
void init(int n){
	for(int i = 1;i <= n;i++)fa[i] = i;
}
int find(int x){
	if(fa[x] == x)return x;
	else{
		fa[x] = find(fa[x]);
		return fa[x];
	}
}
void merge(int x,int y){
	fa[find(x)] = find(y);
}
bool cmp(node x,node y){
	return x.t < y.t;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].x >> a[i].y >> a[i].t;
		a[i].isv = false;
		a[i].vid = 0;
	}
	tot = m;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++)cin >> tmp[j];
		for(int j = 1;j <= n;j++){
			for(int k = j + 1;k <= n;k++){
				tot++;
				a[tot].x = j;
				a[tot].y = k;
				a[tot].t = tmp[j] + tmp[k] + c[i];
				a[tot].isv = true;
				a[tot].vid = i;
			}
		}
	}
	sort(a + 1,a + tot + 1,cmp);
	init(n);
	long long cnt = 0,sum = 0;
	for(int i = 1;i <= tot;i++){
		if(cnt == n - 1)break;
		if(find(a[i].x) != find(a[i].y)){
			sum += a[i].t;
			if(a[i].isv){
				if(flag[a[i].vid])sum -= c[a[i].vid];
				flag[a[i].vid] = true;
			}
			cnt++;
			merge(a[i].x,a[i].y);
		}
	}
	cout << sum << endl;
	return 0;
}
