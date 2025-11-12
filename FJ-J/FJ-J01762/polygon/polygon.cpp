#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int n,a[5010];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n<3) 
	{ 
		printf("0");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int j=3;j<=n;j++)	
	{
		int k=1;
		while(a[k]+a[j-1]<a[j])
		{
			k++;
		}
		if(k>1)
			ans+=j-k;
		else
			ans+=j*2-5;
	}
	ans%=mod;
	printf("%d",ans);
	return 0;
}       
             