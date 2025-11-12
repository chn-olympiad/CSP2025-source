#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005];
long long w[1000005];
long long a[15][10005];
long long c[15];
long long ans,cnt;
long long head[10005];
bool check(){
	for(int i=1; i<=k; i++){
		if(c[i]) return 0;
	} 
	return 1;
}
struct ss{
	int x,y;
	long long z;
};
ss e[1100005];
bool cmp(ss x,ss y){
	return x.z < y.z;
}
int find(int x){
	if(head[x]==x) return x;
	return head[x] = find(head[x]);
}
int main(){
	//24pts
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++){
		cin >> u[i] >> v[i] >> w[i];
	} 
	for(int i=1; i<=k; i++){
		cin >> c[i];
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	if(check()){
		for(int i=1; i<=m; i++){
			e[i].x = u[i];
			e[i].y = v[i];
			e[i].z = w[i];
		}
		cnt = m;
		for(int i=1; i<=k; i++){
			for(int j=1; j<=n; j++){
				cnt++;
				e[cnt].x = j;
				e[cnt].y = n+i;
				e[cnt].z = a[i][j];
			}
		}
		for(int i=0; i<=n+k; i++){
			head[i] = i;
		}
		sort(e+1,e+cnt+1,cmp);
		int all = 0;
		for(int i=1; i<=cnt; i++){
			int h1 = find(e[i].x);
			int h2 = find(e[i].y);
			if(h1==h2) continue;
			all++;
			head[h1] = h2;
			ans += e[i].z;
			if(all==n+k-1) break;
		}
		cout << ans;
	}else{
		for(int i=1; i<=m; i++){
			e[i].x = u[i];
			e[i].y = v[i];
			e[i].z = w[i];
		}
		for(int i=0; i<=n; i++){
			head[i] = i;
		}
		sort(e+1,e+m+1,cmp);
		int all = 0;
		for(int i=1; i<=m; i++){
			int h1 = find(e[i].x);
			int h2 = find(e[i].y);
			if(h1==h2) continue;
			all++;
			head[h1] = h2;
			ans += e[i].z;
			if(all==n-1) break;
		}
		cout << ans;
	}
	return 0;
} 