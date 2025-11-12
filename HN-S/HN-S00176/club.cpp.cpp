#include <bits/stdc++.h>
#define long long int
using namespace std;
int t,n,a[100005][3]={},dp[4005][4005],d1[10005];
bool cmp1(int* a,int* b,int n){
	int tota=0,totb=0;
	for(int i=0;i<n;i++){
		tota+=a[1];
	}
	for(int i=0;i<n;i++){
		totb+=b[1];
	}
	if(tota>totb){
		return true;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		bool Ac=true;
		for(int a1=0;a1<n;a1++){
			for(int a2=0;a2<2;a2++){
				cin>>a[a1][a2];
			}
			if(a[a1][1]!=0 || a[a1][2]!=0){
				Ac=false;
			}
		}
		if(Ac){
			int tot=0;
			for(int ai=0;ai<n;ai++){
				d1[ai]=a[ai][0];
			}
			sort(d1,d1+n);
			for(int ai=0;ai<n/2;ai++){
				tot+=d1[n-ai];
			}
			cout<<tot<<' '<<'o';
			return 0;
		}
	}
	return 12;
		/*
		if(n<=200){
			int tot=0;
			int mx=-1;
			int d[3]={};
			for(int z=n;z>=0;z--){
				mxz=max(a[z][0],max(a[z][1],a[z][2]));
				if(tot+mxz>mx){
					bool o1=false;
					int ik=0;
					for(int i1=0;i1<2;i1++){
						if(a[z][i1]==mxz){
							ik=i1;
						}
					}
					if(d[ik]+1>=n){
						a[z][ik]=-1;;
						
					}
					tot+=mxz;
					mx=tot;
					d[ik]++;
				}
			}
			cout<<mx<<' ';
			continue;
		}
		*/
/*		
3 
4 
4 2 1 
3 2 4 
5 3 4 
3 5 1 
4 
0 1 0 
0 1 0 
0 2 0 
0 2 0 
2 
10 9 8 
4 0 0
*/
//		for(int j=0;j<n;j++){
//			for(int k=0;k<3;k++)	cin>>a[j][k];
//		}
//		sort(a,a+n,cmp1);
//		dp[0][0]=max(a[0][0],max(a[0][1],a[0][2]));
//		for(int j=0;j<n;j++){
//			for(int k=0;k<n;k++){
//				if(a[j][k]>=dp[j][k-1]){
//					dp[j][k]+=max(a[j][0],max(a[j][1],a[j][2]));
//				}else{
//					dp[j][k]+=dp[j=1][k];
//				}
//			}
//		}
//		cout<<dp[n][n];
//	}
//	return 0;
}
