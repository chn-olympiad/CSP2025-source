#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],b,c,lie,hua;
bool mp(int x,int y)
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
	}
	b=a[1];
	sort(a+1,a+1+n*m,mp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			c=i;
			break;
		}
	}
	lie=c/(2*n);
	hua=c%(2*n);
	lie=lie*2;
	if(hua!=0)
	{
		lie++;
	}
	if(hua>n)
	{
		hua=n-(hua-n)+1;
		lie++;
	}
	printf("%d %d",lie,hua);
}
