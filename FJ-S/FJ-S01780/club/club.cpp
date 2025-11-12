#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t, n, a[N][4];
int dfs(int xs, int xr,int ys,int yr, int zs,int zr,int i, int k){
	if(i <= n){
		i++;
		int xxs,yys,zzs,xxr,yyr,zzr;
		if(xr+1 <= k){
			xxs = xs+a[i][1];
			xxr = xr+1;
		}
		if(yr+1 <= k){
			yys = ys+a[i][2];
			yyr = yr+1;
		}
		if(zr+1 <= k){
			zzs = zs+a[i][3];
			zzr = zr+1;
		}
		return max(max(dfs(xxs,xxr,ys,yr,zs,zr,i,k),dfs(xs,xr,yys,yyr,zs,zr,i,k)),dfs(xs,xr,ys,yr,zzs,zzr,i,k));
	}
}
int main() {
	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",a[i][1],a[i][2],a[i][3]);
		}
		cout << dfs(0,0,0,0,0,0,0,n/2);
	}
	return 0;
}

