#include<bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, c, g, sum, ans, a[10005][10005], b[10005], ff[10005];
struct node{
	int x, y, z;
}f[50000000];
bool cmp(node xx, node yy){
	return xx.z<yy.z;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		scanf("%d%d%d", &u, &v, &w);
		a[u][v]=a[v][u]=w;
	}
	for(int i=1; i<=k; i++){
		scanf("%d", &c);
		for(int j=1; j<=n; j++){
			scanf("%d", &b[j]);
		}
		for(int j=1; j<n; j++){
			for(int l=j+1; l<=n; l++){
				if(a[j][l]>0) a[j][l]=a[l][j]=min(a[j][l],c+b[j]+b[l]);
				else a[j][l]=a[l][j]=c+b[j]+b[l];
			}
		}
	}
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			g++;
			f[g].x=i;
			f[g].y=j;
			f[g].z=a[i][j];
		}
	}
	sort(f+1, f+1+g, cmp);
	for(int i=1; i<=g; i++){
		if(ff[f[i].x] && ff[f[i].y]) continue;
		sum++;
		ans+=f[i].z;
		ff[f[i].x]=ff[f[i].y]=1;
	}
	cout<<ans;
	return 0;
}

