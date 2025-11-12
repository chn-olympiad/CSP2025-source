#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			k=i;
			break;
		}
	}
	int l=(k-1)/n+1,r;
	if(l%2==0)
	{
		r=l*n-k+1;
	}
	else
	{
		r=k-(l-1)*n;
	}
	printf("%d %d",l,r);
	return 0;
}
