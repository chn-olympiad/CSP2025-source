#include<bits/stdc++.h>
using namespace std;
#define int long long
const int kMaxN = 1000005,kMaxM = 20005;
int fa[kMaxM],mm,a[kMaxM];
struct node{
	int x,y,z,s;
}e[kMaxN],ee[kMaxN];
bool cmp(node i,node j){
	return i.z < j.z;
}
int find(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}
int n,m,k;
int kruscal(int y){
	for(int i = 1;i <= n+10;i++){
		fa[i] = i;
	}
	int p = n;
	for(int i = 0;i < 10;i++){
		if(y & (1 << i)){
			p++;
		}
	}
	int ans = 0,num = 0;
	for(int i = 1;i <= m;i++){
		int fx = find(e[i].x),fy = find(e[i].y);
		if((e[i].s == -1||((1 << e[i].s) &  y) ) && fx != fy){
			fa[fx]  =   fy;
			ans += e[i].z,num++;
			if(num == p-1){
				break;
			}
		}
	}
	return ans;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> mm >> k;
	for(int i = 1;i <= mm;i++){
		cin >> ee[i].x >> ee[i].y >> ee[i].z;
		ee[i].s = -1;
	}
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	stable_sort(ee+1,ee+1+mm,cmp);
	int num = 0;
	for(int i = 1;i <= mm;i++){
	//	cout << ee[i].x << " " << ee[i].y << '\n';
		if(find(ee[i].x) != find(ee[i].y)){
			e[++m] = ee[i];
		//	cout << e[m].x << " " << e[m].y << " " << e[m].z << " " << e[m].s<< '\n';
			fa[find(ee[i].x)] = find(ee[i].y);
			num++;
			if(num == n-1) break;
		}
	}
	for(int i = 1;i <= k;i++){
		cin >> a[i];
		for(int j = 1;j <= n;j++){
			int x;
			cin >> x;
			e[++m] = (node){n+i,j,x,i-1};
		//	cout << e[m].x << " " << e[m].y << " " << e[m].z << " " << e[m].s<< '\n';
		}
	}
	stable_sort(e+1,e+1+m,cmp);
	int mini = 1e18;
	for(int i = 0;i < (1 << k);i++){
		int ans = 0;
		for(int j = 0;j < k;j++){
			if((1 << j) & i){
				ans += a[j+1];
			}
		}
		//cout << i << " " << kruscal(i) << " " << ans << '\n';
		mini = min(mini,kruscal(i)+ans);
	}
	cout << mini;
	return 0;
}
