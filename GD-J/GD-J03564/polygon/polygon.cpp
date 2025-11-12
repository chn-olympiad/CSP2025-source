#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,l[5005],sum,ans;
bool cmp(int a,int b){return a>b;}
int A(int n,int m)
{
	int sum=1;
	for(int i=n;i>=m;i--)
	{
		sum*=n;
		sum%=998244353;
	}
	return sum;
}
int C(int n,int m){return (A(n,m)/A(m,1))%998244353;}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	sort(l+1,l+n+1,cmp);
	for(int i=n;i;i--)
	{
		sum=l[i];
		for(int j=1;i<=n;j++)
		{
			if(sum>l[i]*2)
			{
				for(int k=j+1;k<=n;k++)
				{
					ans+=C(n,k);
					ans%=998244353;
				}
				break;
			}
			sum+=l[j];
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
