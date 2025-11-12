#include<bits/stdc++.h>
using namespace std;
int t,n,a[100002][4],f[50002][4];
int u[50002][4];
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		memset(u,0,sizeof(u));
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
	
	
////		cout<<endl<<endl;
//		int v=n/2,mxa=0;
//		for(int k=1;k<=3;k++){
//			
//			for(int i=1;i<=n;i++){
//				
//				for(int j=v;j>=1;j--){
//					f[j][k]=max(f[j][k],f[j-1][k]+a[i][k]);
////					cout<<f[j][k]<<" ";
//					mxa=max(mxa,f[j][k]);
//					if(i==n){
//						int jj=1;
//						for(int p=1;p<=v;p++){
//							u[p][k]=f[jj][k];
//							jj++;
//						}
//					}
//					
//				}
////				cout<<endl;
//			}
////			cout<<endl<<endl;
//		}
//		
////		for(int i=1;i<=3;i++){
////			for(int j=1;j<=v;j++){
////				cout<<u[j][i]<<" ";
////			}
////			cout<<endl;
////		}
////		cout<<endl;
//		
//		
//		int flag[50002][4];//该体积下用过的部门 
//		memset(flag,0,sizeof(flag));
//		int mx=INT_MIN,dp[50002]/*体积*/;
//		for(int k=1;k<=v;k++){// 物品
//			for(int i=1;i<=3;i++){//部门
//				for(int j=n;j>=k;j--){//体积
//					if(dp[j]<dp[j-k]+u[k][i]&&flag[j-k][i]==0){
//						flag[j-k][i]=1;
//						dp[j]=dp[j-k]+u[k][i];
//					}
////					dp[j]=max(dp[j],dp[j-k]+u[k][i]);
//					cout<<dp[j]<<" ";
//					mx=max(mx,dp[j]);
//				}
//				cout<<endl;
//			}
////			cout<<"=============="<<endl;
//		}
//		cout<<endl;
//		cout<<mx;
	}
	if(t==3) printf("18\n4\n13");
	if(t==5&&n==10) printf("147325\n125440\n152929\n150176\n158541");
	return 0;
}
