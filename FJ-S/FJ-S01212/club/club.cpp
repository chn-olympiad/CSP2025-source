//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int t,n,minx,a[100005][4],dp[2005][4][2005],maxd[2005][4];
//int main(){
////	freopen("club1.in","r",stdin);
////	freopen("club.out","w",stdout);
//	scanf("%d",&t);
//	while(t--){
//		scanf("%d",&n);
//		for(int i = 1;i <= n;i++){
//			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
//			for(int j = 0;j < 3;j++){
//				maxd[i][j] = 0;
//				dp[0][j][i] = 0;
//			}
//		}
//		for(int i = 1;i <= n;i++){
//			for(int j = 0;j < 3;j++){
//				minx = min(i,n/2);
//				for(int k = 1;k <= minx;k++){
//					dp[i][j][k] = dp[i-1][j][k-1];
//					for(int l = 0;l < 3;l++){
//						if(j != l){
//							dp[i][j][k] = max(dp[i][j][k],maxd[i-1][l]);
//						}
//					}
//					dp[i][j][k] += a[i][j];
//					maxd[i][j] = max(maxd[i][j],dp[i][j][k]);
//				}
//			}
//		}
//		printf("%d\n",max(maxd[n][0],max(maxd[n][1],maxd[n][2])));
//	}
//	return 0;
//}
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,ans,res,cntx,cnty,cntz,sum1,sum2,sum3,task,cnt1,cnt2;
struct node{
	int x,y,z;
}d[100005];
void dfs(int p,int a,int b,int c,int sum){
	if(p > n){
		ans = max(ans,sum);
		return ;
	}
	if(a * 2 < n) dfs(p+1,a+1,b,c,sum+d[p].x);
	if(b * 2 < n) dfs(p+1,a,b+1,c,sum+d[p].y);
	if(c * 2 < n) dfs(p+1,a,b,c+1,sum+d[p].z);
}
bool cmp1(node c,node d){
	if(c.x == d.x){
		if(c.y == d.y) return c.z > d.z;
		return c.y > d.y;
	}
	return c.x > d.x;
}
bool cmp2(node c,node d){
	if(c.x == d.x){
		if(c.z == d.z) return c.y > d.y;
		return c.z > d.z;
	}
	return c.x > d.x;
}
bool cmp3(node c,node d){
	if(c.y == d.y){
		if(c.x == d.x) return c.z > d.z;
		return c.x > d.x;
	}
	return c.y > d.y;
}
bool cmp4(node c,node d){
	if(c.y == d.y){
		if(c.z == d.z) return c.x > d.x;
		return c.z > d.z;
	}
	return c.y > d.y;
}
bool cmp5(node c,node d){
	if(c.z == d.z){
		if(c.x == d.x) return c.y > d.y;
		return c.x > d.x;
	}
	return c.z > d.z;
}
bool cmp6(node c,node d){
	if(c.z == d.z){
		if(c.y == d.y) return c.x > d.x;
		return c.y > d.y;
	}
	return c.z > d.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].z);
		}
		ans = res = cnt1 = cnt2 = 0;
		if(n > 20){
				cntx = cnty = cntz = ans = 0;
		if(sum1 >= sum2 && sum1 >= sum3){
			if(sum2 >= sum3){
				sort(d+1,d+n+1,cmp1);
				for(int i = 1;i <= n;i++){
					if(cntx < n/2 || (cnty >= n/2 && cntz >= n/2)){
						cntx ++;
						ans += d[i].x;
					}
					else if(cnty < n/2 || (cntx >= n/2 && cntz >= n/2)){
						cnty ++;
						ans += d[i].y;
					}
					else{
						cntz ++;
						ans += d[i].z;
					}
				}
			}
			else{
				sort(d+1,d+n+1,cmp2);
				for(int i = 1;i <= n;i++){
					if(cntx < n/2 || (cnty >= n/2 && cntz >= n/2)){
						cntx ++;
						ans += d[i].x;
					}
					else if(cntz < n/2 || (cntx >= n/2 && cnty >= n/2)){
						cntz ++;
						ans += d[i].z;
					}
					else{
						cnty ++;
						ans += d[i].y;
					}
				}
			}
		}
		else if(sum2 >= sum1 && sum2 >= sum3){
			if(sum1 >= sum3){
				sort(d+1,d+n+1,cmp3);
				for(int i = 1;i <= n;i++){
					if(cnty < n/2 || (cntx >= n/2 && cntz >= n/2)){
						cnty ++;
						ans += d[i].y;
					}
					else if(cntx < n/2 || (cnty >= n/2 && cntz >= n/2)){
						cntx ++;
						ans += d[i].x;
					}
					else{
						cntz ++;
						ans += d[i].z;
					}
				}
			}
//			else{
//				sort(a+1,a+n+1,cmp4);
//				for(int i = 1;i <= n;i++){
//					if(cnty < n/2 || (cntx >= n/2 && cntz >= n/2)){
//						cnty ++;
//						ans += d[i].y;
//					}
//					else if(cntz < n/2 || (cntx >= n/2 && cnty >= n/2)){
//						cntz ++;
//						ans += a[i].z;
//					}
//					else{
//						cntx ++;
//						ans += a[i].x;
//					}
//				}
//			}
//		}
//		else{
//			if(sum1 >= sum2){
//				sort(a+1,a+n+1,cmp5);
//				for(int i = 1;i <= n;i++){
//					if(cntz < n/2 || (cnty >= n/2 && cntx >= n/2)){
//						cntz ++;
//						ans += a[i].z;
//					}
//					else if(cntx < n/2 || (cnty >= n/2 && cntz >= n/2)){
//						cntx ++;
//						ans += a[i].x;
//					}
//					else{
//						cnty ++;
//						ans += a[i].y;
//					}
//				}
//			}
//			else{
//				sort(a+1,a+n+1,cmp6);
//				for(int i = 1;i <= n;i++){
//					if(cntz < n/2 || (cnty >= n/2 && cntx >= n/2)){
//						cntz ++;
//						ans += a[i].z;
//					}
//					else if(cnty < n/2 || (cntx >= n/2 && cntz >= n/2)){
//						cnty ++;
//						ans += a[i].y;
//					}
//					else{
//						cntx ++;
//						ans += a[i].x;
//					}
//				}
//			}
//		}	
		}
		else{
			dfs(1,0,0,0,0);
		}
		printf("%d\n",ans);
	}
}
	return 0;
}
//4
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
