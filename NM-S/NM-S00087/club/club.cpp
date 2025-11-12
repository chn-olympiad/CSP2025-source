#include<bits/stdc++.h>
using namespace std;
int t,n,q[100005][4];
long long ans;
int a[5];
long long dp(int i,long long sum)
{
	if(i>=n){
		ans=max(ans,sum);
		return 0;
	}
	for(int k=1;k<=3;k++)
	    if(a[k]<n/2){
		a[k]++;
		dp(i+1,sum+q[i+1][k]);
		a[k]--;
	}
	return 0;
}
int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	scanf("%d",&t); 
	for(int qqqqq=1;qqqqq<=t;qqqqq++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&q[i][1],&q[i][2],&q[i][3]);
		ans=0;
		a[1]=a[2]=a[3]=0;
		dp(0,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
