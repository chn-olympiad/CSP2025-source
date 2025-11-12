#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N][5],num[N][5][5],t,n,a[N][5];
int main(){
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
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		//num[i][j][k]为第i个同学选择j俱乐部时，k俱乐部的人数 
		//dp[i][j][k]为到第i位同学，并且该同学选择第j个俱乐部时，第i-1位同学选择k俱乐部时的最大兴趣度
		for(int j=1;j<=3;j++){
			dp[1][j]=a[1][j],num[1][j][j]=1;
		}
		for(int i=2;i<=n;i++){//第i位同学 
			for(int j=1;j<=3;j++){//第i位同学选择的俱乐部为j 
				for(int k=1;k<=3;k++){//第i-1位同学选择的俱乐部为k 
					if(num[i-1][k][j]>=(n/2)){
						for(int tmp=1;tmp<=3;tmp++){
							num[i][j][tmp]=num[i-1][k][tmp];
						}
						continue;
					}
					if(dp[i-1][k]+a[i][j]>dp[i][j]){
//						cout<<i<<" "<<j<<" "<<k<<endl;
						dp[i][j]=dp[i-1][k]+a[i][j];
						for(int tmp=1;tmp<=3;tmp++){
							num[i][j][tmp]=num[i-1][k][tmp]+(int)(tmp==j);
						}
					}
				}
			}
//			for(int j=1;j<=3;j++){
//				for(int k=1;k<=3;k++){
//					if(num[i][j][k]){
//						continue;
//					}
//					num[i][j][k]=num[i-1][j][k];
//				}
//			}
//			cout<<endl;
		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				for(int k=1;k<=3;k++){
//					cout<<num[i][j][k]<<" ";
//				}
//				cout<<"NEXT:";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
		int ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
		printf("%d\n",ans);
	}
	return 0;
} 
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
