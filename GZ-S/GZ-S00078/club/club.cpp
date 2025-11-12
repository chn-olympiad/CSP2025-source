//GZ-S00078 贵阳市南明区李端棻中学 向一坤
#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+7;
struct st{
	int a1,a2,a3;
}t[mx];
int T;
int n;
bool cmp1(st a,st b){return a.a1>b.a1;}
bool cmp2(int a,int b){return a>b;}
void A(){
	sort(t+1,t+n+1,cmp1);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=t[i].a1;
	}
	printf("%d\n",ans);
}
//void B(){
//	sort(a1+1,a1+n+1,less<int>);
//	int ans=0;
//	for(int i=1;i<=n/2;i++){
//		ans+=a1[i];
//	}
//	printf("%d\n",ans);
//}
int dp[205][205][205];
void _200(){
	int ans=0;
	dp[1][1][0]=t[1].a1;dp[1][0][1]=t[1].a2;dp[1][0][0]=t[1].a3;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++){
				if(j==0&&k==0) dp[i][j][k]=dp[i-1][j][k]+t[i].a3;
				else if(j==i) dp[i][j][k]=dp[i-1][j-1][k]+t[i].a1;
				else if(k==i) dp[i][j][k]=dp[i-1][j][k-1]+t[i].a2;
				else if(j==0) dp[i][j][k]=max(dp[i-1][j][k-1]+t[i].a2,dp[i-1][j][k]+t[i].a3);
				else if(k==0) dp[i][j][k]=max(dp[i-1][j-1][k]+t[i].a1,dp[i-1][j][k]+t[i].a3);
				else if(k+j==i) dp[i][j][k]=max(dp[i-1][j][k-1]+t[i].a2,dp[i-1][j-1][k]+t[i].a1);
				else dp[i][j][k]=max(dp[i-1][j-1][k]+t[i].a1,max(dp[i-1][j][k-1]+t[i].a2,dp[i-1][j][k]+t[i].a3));
				if(i==n&&j<=n/2&&k<=n/2&&(i-j-k)<=n/2){
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
	}
	
	printf("%d\n",ans);
}
int ccccc[mx<<2];
void _hyw(){
	int k=0;
	for(int i=1;i<=n;i++) if(t[i].a1>=500) ccccc[++k]=t[i].a1;
	for(int i=1;i<=n;i++) if(t[i].a2>=500) ccccc[++k]=t[i].a2;
	for(int i=1;i<=n;i++) if(t[i].a3>=500) ccccc[++k]=t[i].a3;
	sort(ccccc+1,ccccc+k+1,cmp2);
	int ans=0;
	for(int i=1;i<=n;i++) ans+=ccccc[i];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int z2=1,z3=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&t[i].a1,&t[i].a2,&t[i].a3);
			if(t[i].a2!=0) z2=0;
			if(t[i].a3!=0) z3=0;
		}
		if(z2&&z3) A();//5pts
		else if(n<=200) _200();//55pts
		else _hyw();//maybe 10pts?
	}
	return 0;
}
