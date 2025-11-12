#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int n,x[n],y[n],z[n],xs = 0,ys = 0,zs = 0;
		scanf("%d",&n);
		int a[n][4];
		for(int i = 0;i<n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				x[xs]= i;
				xs++;
			} else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				y[ys]= i;
				ys++;
			}
		}
		xs--;
		ys--;
		if(xs>n/2){
			for(int j = 0;j<xs-(n/2);j++){
				int min = 1e5;
				for(int i = 0;i<=xs;i++){
					if(a[x[i]][1]<min){
						min = i;
					}
				}
				if(a[x[min]][2] > a[x[min]][3] && ys <= n/2){
					ys++;
					y[ys] = x[min];
				} else {
					zs++;
					z[zs] = x[min];
				}
				x[min] = -1;
				xs--;
			}
		}
		if(ys>n/2){
			for(int j = 0;j<ys-(n/2);j++){
				int min = 1e5;
				for(int i = 0;i<=ys;i++){
					if(a[y[i]][2]<min){
						min = i;
					}
				}
				if(a[y[min]][3] > a[y[min]][1] && zs <= n/2){
					zs++;
					z[zs] = y[min];
				} else {
					xs++;
					x[xs] = y[min];
				}
				y[min] = -1;
				ys--;
			}
		}
		int ans = 0;
		for(int i = 0;i<xs;i++){
			ans += a[x[i]][1];
		}
		for(int i = 0;i<ys;i++){
			ans += a[y[i]][2];
		}
		for(int i = 0;i<zs;i++){
			ans += a[z[i]][3];
		}
		printf("%d\n",ans);
	}
	return 0;
}
