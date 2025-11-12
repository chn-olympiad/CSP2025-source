#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct node{
	int a[4],v;
};
node dp[100005][4];
bool cmp(node a,node b){
	if(a.a[1]==a.a[2]||a.a[2]==a.a[3]||a.a[1]==a.a[2]){
		return 1;
	}
	if(a.a[1]>b.a[1]){
		return a.a[1]<b.a[1];
	}
	if(a.a[2]>b.a[2]){
		return a.a[2]<b.a[2];
	}
	return a.a[3]<b.a[3];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		vector<int> a;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&dp[i][1].v,&dp[i][2].v,&dp[i][3].v);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				
				int maxn=0,mi=0;
				for(int k=1;k<=3;k++){
					if(dp[i-1][k].a[j]+1<=n/2&&dp[i-1][k].v>=maxn){
						maxn=dp[i-1][k].v;
						mi=k;
					}
				}
				dp[i][j].v+=maxn;
				dp[i][j].a[1]=dp[i-1][mi].a[1],dp[i][j].a[2]=dp[i-1][mi].a[2],dp[i][j].a[3]=dp[i-1][mi].a[3],dp[i][j].a[j]++;
			
			}
		}
		
		cout<<max(dp[n][1].v,max(dp[n][2].v,dp[n][3].v))<<endl;
	} 
}
