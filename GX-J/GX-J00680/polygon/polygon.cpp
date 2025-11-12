#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[5001];
int ans;
void ds(int x,int h,int z,int y)
{
	if(x>=3&&h>2*z)
	{
		ans++;
	}
	for(int i=y+1;i<=n;i++)
	{
		int z1=max(z,a[i]);
		h+=a[i];
		x++;
		ds(x,h,z1,i);
		x--;
		h-=a[i];
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ds(0,0,0,0);
	printf("%d",ans);
	return 0;
}
