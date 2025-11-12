#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m*n;i++)
	{
		scanf("%d",&a[i]);
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			t=i;
			break;
		}
	}
	int r=t%(2*n),c=t/(2*n)*2+1;
	if(r==0) r=1,c++;
	else if(r>n) r=2*n-r+1,c++;
	printf("%d %d",c,r);
	return 0;
}