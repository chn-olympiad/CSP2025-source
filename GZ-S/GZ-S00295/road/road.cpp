//GZ-S00295 遵义市第五中学 江信杰
#include <bits/stdc++.h>
using namespace std;
int n,m,k,sum=0,mn=2e9;
int a[10005][3];
int b[11][10005],c[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(mn>a[i][j]){
				mn=a[i][j];
			}
		}
		sum+=mn;
	}
	printf("%d",sum);
	return 0;
}



