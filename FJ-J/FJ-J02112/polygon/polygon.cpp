#include<bits/stdc++.h>
using namespace std;
int n,a[5005],fl=1,ans,maxn=INT_MIN;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		if(a[i]>1) fl=0;
	}
	if(n<3) printf("%d",0);
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*maxn) printf("%d",1);
		else printf("%d",0);
	}
	if(fl)
		printf("%d",n/3);
	return 0;
}
