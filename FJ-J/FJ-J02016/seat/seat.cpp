#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,zrs,chengji,paimin;//n:hang m:lie
	scanf("%d%d",&n,&m);
	zrs=n*m;
	scanf("%d",&a[1]);
	chengji=a[1];
	for(int i=2;i<=zrs;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+zrs+1,cmp);
	int l=1,r=zrs;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid]==chengji)
		{
			l=mid;
			break;
		}
		else if(a[mid]>chengji)
		{
			l=mid+1;
		}
		else r=mid;
	}
	paimin=l;
	int lie=paimin/n,hang;
	if(paimin%n!=0)lie++;
	if(lie%2!=0)hang=((paimin-1)%n)+1;
	else hang=n-((paimin-1)%n);
	printf("%d %d",lie,hang);
	return 0;
}
