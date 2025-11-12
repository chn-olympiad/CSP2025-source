#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int N=2e5+10;
int T,n,ma;
struct tp{
	int a[4];
	int m[4];
	const int get(int i) const{
		return a[m[i]];
	}
}a[N];
void fx(tp &o){
	for(int i=1;i<=3;i++)o.m[i]=i;
	if(o.get(1)<o.get(2)){
		swap(o.m[1],o.m[2]);
	}
	if(o.get(2)<o.get(3)){
		swap(o.m[2],o.m[3]);
	}
	if(o.get(1)<o.get(2)){
		swap(o.m[1],o.m[2]);
	}
}
bool cmp(tp &x,tp &y){
	if(x.get(1)!=y.get(1))return x.get(1)>y.get(1);
	if(x.get(2)!=y.get(2))return x.get(2)>y.get(2);
	return x.get(3)>y.get(3);
}
long long dp[N][4];
int sl[N][4][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(sl,0,sizeof(sl));
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		ma=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a[1],&a[i].a[2],&a[i].a[3]);
			fx(a[i]);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(sl[i-1][k][j]<ma){
						if(dp[i][j]<dp[i-1][k]+a[i].a[j]){
							for(int l=1;l<=3;l++)sl[i][j][l]=sl[i-1][k][l];
							sl[i][j][j]=sl[i-1][k][j]+1;
							dp[i][j]=dp[i-1][k]+a[i].a[j];
						}
					}
				}
				for(int k=1;k<=3;k++)printf("%d,",sl[i][j][k]);
				printf("%lld ",dp[i][j]);
			}
			printf("\n");
		}
		printf("%lld\n",max(dp[n][1],max(dp[n][2],dp[n][3])));
	}
	return 0;
}
