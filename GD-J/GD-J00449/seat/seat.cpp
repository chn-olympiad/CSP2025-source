#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(i==1) s=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			s=i;
			break;
		}
	}
	int k=s/m;
	if(s%m>0) k++;
	printf("%d ",k);
	if(k&1)
	{
		if(k==1) printf("%d",s);
		else printf("%d",s%m);
	}
	else printf("%d",m-s%m+1);
	return 0;
}
