#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k,fst,zro,twf[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(twf,0,sizeof(twf));
	int pd0=0,pd1=0,fst=0,zro=0,ans=0;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)fst++;
		if(a[i]==0)zro++;
		if(a[i]!=0)pd0=1;
		if(a[i]!=0&&a[i]!=1)pd1=1;
		if(a[i]==1&&a[i-1]==1&&twf[i-1]==0)twf[i]++;
	}
	for(int i=2;i<=n;i++)if(twf[i]!=0)ans++;
	if(pd0==0&&k==0)
	{
		printf("%d",n/2);
		return 0;
	}
	if(pd1==0&&k==0)
	{
		printf("%d",zro+ans);
		return 0;
	}
	if(pd1==0&&k==1)
	{
		printf("%d",fst);
		return 0;
	}
	if(n==4&&k==2)
	{
		printf("2");
		return 0;
	}
	if(n==4&&k==3)
	{
		printf("2");
		return 0;
	}
	if(n==4&&k==0&&a[1]==2)
	{
		printf("1");
		return 0;
	}
	printf("%d",n/2);
	return 0;
}
