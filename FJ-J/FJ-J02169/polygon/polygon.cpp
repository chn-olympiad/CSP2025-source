#include<bits/stdc++.h>
using namespace std;
int n,a[5005],being[5005],ans,cnt=1,si,p,q,l=1;
void cdis(int x)
{
	if(x==0)
	{
		if(p>q*2)ans++;
		p=0;q=0;l=1;
		return ;
	}
	for(int i=l;i<=n-x+1;i++)
	{
		p+=a[i];
		q=max(q,a[i]);
		l=i+1;
		cdis(x-1);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	//if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])printf("1");
	//else printf("0");
	for(si=3;si<=n;si++)
	{
		p=0;q=0;l=1;
		cdis(si);
	}
	printf("%d",ans%998244353);
	return 0;
}
