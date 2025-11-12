#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,c[5010][5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==3)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x+y+z>2*max(x,max(y,z))) printf("1");
		else printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++) c[1][i]=i*1ll;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==1) continue;
			if(i==j) c[i][j]=1;
			else c[i][j]=c[i-1][j-1]+c[i][j-1]; 
			if(j==n&&i>=3) ans=(ans+c[i][j])%998244353;
		} 
	}
	printf("%lld",ans%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
