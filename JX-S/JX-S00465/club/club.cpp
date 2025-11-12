#include<bits/stdc++.h>
using namespace std;
int t;
int ans;
const int N=100100;
int a[N][4];
int cntf,cnts,cntt;
void dfs(int k,int sum,int n){
	if(k==n+1){
		ans=max(ans,sum);
	}
		if(cntf<n/2){
			cntf++;
			dfs(k+1,sum+a[k][1],n);
			cntf--;
		}
		if(cnts<n/2){
			cnts++;
			dfs(k+1,sum+a[k][2],n);
			cnts--;
		}
		if(cntt<n/2){
			cntt++;
			dfs(k+1,sum+a[k][3],n);
			cntt--;
		}
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-1;
		cntf=0;
		cnts=0;
		cntt=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		}
		if(n<=30){
			dfs(1,0,n);
			printf("%d",ans);
		}
		
	}
	return 0;
}
