#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5];
int dp[105][105][105];
int dfs(int c1,int c2,int c3){
	if(dp[c1][c2][c3]!=-0x3f3f3f3f) return dp[c1][c2][c3];
	int k=c1+c2+c3;
	if(k==n+1){
		dp[c1][c2][c3]=0;
		return 0;
	}
	int d1=-0x3f3f3f3f;
	int d2=-0x3f3f3f3f;
	int d3=-0x3f3f3f3f;
	if(c1+1<=n/2) d1=dfs(c1+1,c2,c3)+a[k][1];
	if(c2+1<=n/2) d2=dfs(c1,c2+1,c3)+a[k][2];
	if(c3+1<=n/2) d3=dfs(c1,c2,c3+1)+a[k][3];
	dp[c1][c2][c3]=max(d1,max(d2,d3));
	return max(d1,max(d2,d3));
}
bool checkA(){
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0) return 0;
		if(a[i][3]!=0) return 0;
	}
	return 1;
}
int b[100005];
bool cmp(int x,int y){
	return x>y;
}
void solveA(){
	for(int i=1;i<=n;i++){
		b[i]=a[i][1];
	}
	sort(b+1,b+1+n,cmp);
	int sum=0;
	for(int i=1;i<=n/2;i++){
		sum+=b[i];
	}
	printf("%d",sum);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		if(checkA()){
			solveA();
			continue;
		}
		for(int j1=n/2;j1>=0;j1--){
			for(int j2=n/2;j2>=0;j2--){
				for(int j3=n/2;j3>=0;j3--){
					dp[j1][j2][j3]=-0x3f3f3f3f;
				}
			}
		}
		printf("%d\n",dfs(0,0,0));
	}
	return 0;
}
/*
 !"#$%&'()*+,-./0123456789:;<=>?@
 ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`
 abcdefghijklmnopqrstuvwxyz{|}~
*/
