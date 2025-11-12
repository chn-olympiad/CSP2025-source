#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	if(n==3)
	{
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))) ans++;
	}
	if(n==4)
	{
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))) ans++;
		if(a[0]+a[1]+a[3]>2*max(a[0],max(a[1],a[3]))) ans++;
		if(a[1]+a[2]+a[3]>2*max(a[2],max(a[1],a[3]))) ans++;
		if(a[0]+a[3]+a[2]>2*max(a[0],max(a[3],a[2]))) ans++;
		if(a[0]+a[1]+a[2]+a[3]>2*max(a[0],max(a[1],max(a[2],a[3])))) ans++;
	}
	if(n==5)
	{
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))) ans++;
		if(a[0]+a[1]+a[3]>2*max(a[0],max(a[1],a[3]))) ans++;
		if(a[0]+a[3]+a[2]>2*max(a[0],max(a[3],a[2]))) ans++;
		if(a[0]+a[1]+a[4]>2*max(a[0],max(a[1],a[4]))) ans++;
		if(a[1]+a[2]+a[3]>2*max(a[2],max(a[1],a[3]))) ans++;
		if(a[0]+a[2]+a[4]>2*max(a[0],max(a[2],a[4]))) ans++;
		if(a[0]+a[3]+a[4]>2*max(a[0],max(a[3],a[4]))) ans++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))) ans++;
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))) ans++;
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3],a[4]))) ans++;
		if(a[0]+a[1]+a[2]+a[3]>2*max(a[0],max(a[1],max(a[2],a[3])))) ans++;
		if(a[0]+a[1]+a[2]+a[4]>2*max(a[0],max(a[1],max(a[2],a[4])))) ans++;
		if(a[0]+a[1]+a[4]+a[3]>2*max(a[0],max(a[1],max(a[4],a[3])))) ans++;
		if(a[0]+a[3]+a[2]+a[4]>2*max(a[0],max(a[3],max(a[2],a[4])))) ans++;
		if(a[4]+a[1]+a[2]+a[3]>2*max(a[0],max(a[1],max(a[2],a[3])))) ans++;
		if(a[0]+a[1]+a[2]+a[3]+a[4]>2*max(a[0],max(a[1],max(a[2],max(a[3],a[4]))))) ans++;
	}
	printf("%d",ans);
	return 0;
}
