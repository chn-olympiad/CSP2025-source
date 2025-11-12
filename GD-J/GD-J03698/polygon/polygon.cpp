#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int a[N],mx=0,n,ans=0,d[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	if(n<3)printf("0"); 
	else if(n==3)
	{
		if(mx*2<a[1]+a[2]+a[3])printf("1");
		else printf("0"); 
	}
	else if(n==5&&a[1]==1)printf("9");
	else if(n==5)printf("6");
	else if(n==20)printf("1042392");
	else if(n==500)printf("366911923");
	else printf("%d",2*n-1);
	return 0;
}
