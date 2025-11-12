#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int di=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)printf("%d ",a[i]);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==di)
		{
			di=i;
			break;
		}
	}
	int h,l;
	l=(ceil(di*1.0/n*1.0));
	if(l%2==1)
	{
		h=di-(l-1)*n;
	}
	else if(l%2==0)
	{
		h=n-(di-(l-1)*n)+1;
	}
	printf("%d %d",l,h);
	return 0;
}
