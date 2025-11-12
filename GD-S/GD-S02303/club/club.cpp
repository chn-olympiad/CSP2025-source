#include<bits/stdc++.h>
using namespace std;
struct datay
{
	long long x,y,z,p;
}a[100005];
int n,s1,s2,s3;
long long s,t[100005],m;
void poi()
{
	scanf("%d",&n),s=s1=s2=s3=m=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z)s+=a[i].x,s1++,a[i].p=1;
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)s+=a[i].y,s2++,a[i].p=2;
		else s+=a[i].z,s3++,a[i].p=3;
	}
	if(s1<=n/2&&s2<=n/2&&s3<=n/2){printf("%lld\n",s);return;}
	for(int i=1;i<=n;i++)
	{
		if(a[i].p==1&&s1>=n/2)t[++m]=a[i].x-max(a[i].y,a[i].z);
		else if(a[i].p==2&&s2>=n/2)t[++m]=a[i].y-max(a[i].x,a[i].z);
		else if(a[i].p==3&&s3>=n/2)t[++m]=a[i].z-max(a[i].x,a[i].y);
	}
	sort(t+1,t+m+1),s1=max(s1,max(s2,s3));
	for(int i=1;i<=s1-n/2;i++)s-=t[i];
	printf("%lld\n",s);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int qwe;
	scanf("%d",&qwe);
	for(int i=1;i<=qwe;i++)poi();








  return 0;
}

