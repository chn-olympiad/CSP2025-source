#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5+10;
int n,k;
int num[N],dp[N],ans[10005][10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int xorn=num[j+1];
			for(int k=j+1;k<=i;k++)
				xorn^=num[j];
			if(xorn==k)
				ans[j][i]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((i==j&&num[i]==k)||(ans[i][j]&&i!=j)){
				//printf("%d %d\n",i,j);
				dp[j]=max(dp[j-1]+1,1);
			}
			else dp[j]=dp[j-1];
		}
	}
	printf("%d",dp[n]);
	return 0;
}
