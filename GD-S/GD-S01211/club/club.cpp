#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n,t;
long long dp[210000][5]={0};
struct item{
	int x,y,z,id;
}it,a[210000];
bool cmp(item A,item B){
	if(A.x==B.x){
		if(A.y==B.y)return A.z>B.z;
		return A.y>B.y;
	}
	return A.x>B.x;
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n/2;i++){
			for(int j=0;j<=4;j++)dp[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a+1,a+1+n,cmp);
		/*for(int i=1;i<=n;i++){
			printf("%d %d %d\n",a[i].x,a[i].y,a[i].z);
		}*/
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			long long q=dp[x][1],p=dp[y][2],e=dp[z][3];
			for(int j=n/2;j>=1;j--){
				if(a[i].x&&((j-1==0)||dp[j-1][1])){
					dp[j][1]=max(max(dp[j-1][1],max(p,e))+a[i].x,dp[j][1]);
					x<n/2?x++:x=n/2;
				}
				if(a[i].y&&((j-1==0)||dp[j-1][2])){
					dp[j][2]=max(max(dp[j-1][2],max(q,e))+a[i].y,dp[j][2]);
					y<n/2?y++:y=n/2;
					
				}
				if(a[i].z&&((j-1==0)||dp[j-1][3])){
					dp[j][3]=max(max(dp[j-1][3],max(p,q))+a[i].z,dp[j][3]);
					z<n/2?z++:z=n/2;
				}
				//printf("%d %d %d\n",dp[j][1],dp[j][2],dp[j][3]);
			}
		} 
		printf("%lld\n",max(dp[x][1],max(dp[y][2],dp[z][3])));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
