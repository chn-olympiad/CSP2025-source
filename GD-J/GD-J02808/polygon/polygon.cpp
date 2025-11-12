#include<bits/stdc++.h>
using namespace std;
int d,d1,n,m,a[5005],ans,ans1,g;
void amns(int m)
{
	if(g>ans1)
	{
		ans++;
		ans%=998244353;
	}
	for(int j=m+1;j<d1;j++)
	{
		g+=a[j];
		amns(j);
		g-=a[j];
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		d=i;
		while(a[d]<a[d-1]&&d>1)
		{
			d1=a[d-1];
			a[d-1]=a[d];
			a[d]=d1;
			d--;
		}
	}
	for(int i=3;i<=n;i++)
	{
		ans1=a[i];
		d1=i;
		amns(0);
	}
	printf("%d",ans);
}
