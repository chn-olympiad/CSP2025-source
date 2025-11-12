#include<bits/stdc++.h>
using namespace std;
int b[11],d=1,d1,n,m,a[1005],ans,ans1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[1]) d++;
	}
	ans1=d%n;
	ans=d/n+1;
	if(ans1==0)
	{
		ans--;
		ans1=n;
	}
	if(ans%2==0) ans1=n+1-ans1;
	printf("%d %d",ans,ans1);
}
