//GZ-S00455 陈俊洁 周林学校
//nmd屎山代码
#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t;
struct club {
	int f;
	int s;
	int t;
} a[N];
int n;
int mx[N],mid[N],mn[N];
//int mx_x[3][N],md_x[3][N],mn[3][N;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int v1=0,v2=0,v3=0;
		int ans=0;
		cin>>n;
		int s=n/2;
		for(int i=1; i<=n; i++) {
			cin>>a[i].f>>a[i].s>>a[i].t;
			mx[i]=max(a[i].f,max(a[i].s,a[i].t));
			mn[i]=min(a[i].f,min(a[i].s,a[i].t));
			mid[i]=min(a[i].f,max(a[i].s,a[i].t));
			if(mx[i]==a[i].f) {
				v1++;
				ans+=mx[i];
				if(v1>s) {
					v1--;
					ans-=mx[i];
					if(mid[i]==a[i].s) {
						v2++;
						ans+=mid[i];
						if(v2>s) {
							v2--;
							ans-=mid[i];
							if(mn[i]==a[i].t) {
								v3++;
								ans+=mn[i];
							}
						}
					} else if(mid[i]==a[i].t) {
						v3++;
						ans+=mid[i];
						if(v3>s) {
							v3--;
							ans-=mid[i];
							if(mn[i]==a[i].s) {
								v2++;
								ans+=mn[i];
							}
						}
					}
				}
			}
//	__________________________________________________
			else if(mx[i]==a[i].s) {
				v2++;
				ans+=mx[i];
				if(v2>s) {
					v2--;
					ans-=mx[i];
					if(mid[i]==a[i].f) {
						v1++;
						ans+=mid[i];
						if(v1>s) {
							v1--;
							ans-=mid[i];
							if(mn[i]==a[i].t) {
								v3++;
								ans+=mn[i];
							}
						}
					} else if(mid[i]==a[i].t) {
						v3++;
						ans+=mid[i];
						if(v3>s) {
							v3--;
							ans-=mid[i];
							if(mn[i]==a[i].f) {
								v1++;
								ans+=mn[i];
							}
						}
					}
				}
			}
				//	______我真的。。___________________________________________
			if(mx[i]==a[i].t) {
				v3++;
				ans+=mx[i];
				if(v3>s) {
					v3--;
					ans-=mx[i];
					if(mid[i]==a[i].s) {
						v2++;
						ans+=mid[i];
						if(v2>s) {
							v2--;
							ans-=mid[i];
							if(mn[i]==a[i].f) {
								v1++;
								ans+=mn[i];
							}
						}
					} else if(mid[i]==a[i].f) {
						v1++;
						ans+=mid[i];
						if(v1>s) {
							v1--;
							ans-=mid[i];
							if(mn[i]==a[i].s) {
								v2++;
								ans+=mn[i];
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//nmd屎山代码，md光是括号都搞半天
//以上代码是实在没招了 
//个人思路为以下代码 没调对 


////GZ-S00455 陈俊洁 周林学校
//#include<bits/stdc++.h>
//#define N 300005
//using namespace std;
//int t;
//int a[N][3];
//int dp[N][3];
//int n;
//int main() {
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	cin>>t;
//	while(t--) {
//		memset(dp,0,sizeof(dp));
//		cin>>n;
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=3; j++) {
//				cin>>a[i][j];
//			}
//		}
//		int v[3];
//		for(int i=1; i<=3; i++) {
//			dp[1][i]=a[1][i];
//			v[i]=0;
//		}
//
//		for(int i=2; i<=n; i++) {
//			for(int j=1; j<=3; j++) {
////				if(v1>n/2) {
////					if(v2>n/2){
////						dp[i][j]=dp[i-1][3]+a[i][j];
////						v[j]++;
////					}else if(v3>n/2){
////						dp[i][j]=dp[i-1][2]+a[i][j];
////
////					}else {
////						dp[i][j]=max(dp[i-1][2],dp[i-1][3])+a[i][j];
////
////					}
////				}else if(v2>n/2){
////					if(v3>n/2){
////						dp[i][j]=dp[i-1][1];
////					}else{
////						dp[i][j]=max(dp[i-1][1],dp[i-1][3]);
////					}
////				}else if(v3>n/2){
////					dp[i][j]=max(dp[i-1][1],dp[i-1][2]);
////				}else{}
//				if(v[j]>n/2) continue;
//				else {
//					if(i==2) {
//						int tmp;
//						tmp=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
//						for(int z=1;z<=3;z++) if(tmp==dp[1][z]) v[z]++;
//					}
//					dp[i][j]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][j];
//					v[j]++;
//				}
//			}
//		}
//		int mx=0;
//		for(int i=1; i<=3; i++) {
//			if(mx<=dp[n][i]) mx=dp[n][i];
////			cout<<dp[n][i]<<"___"<<endl;
//		}
//		cout<<mx;
//	}
////	fclose(stdin);
////	fclose(stdout);
//	return 0;
//}
 
