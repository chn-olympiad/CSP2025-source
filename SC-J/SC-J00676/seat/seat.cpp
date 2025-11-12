#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int a[maxn*maxn],b[maxn][maxn];
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i) scanf("%d",&a[i]);
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=0,s=0;
	for(int i=1;i<=n*m;++i)
	{
		++s;
		if(y==m&&x%2==1)
		{
			++x;
			y=m;
		}
		else if(y==1&&x%2==0)
		{
			++x;
			y=1;
		}
		else if(x%2==1)
		{
			++y;
		}
		else if(x%2==0)
		{
			--y;
		}
		if(a[s]==p) break;
	}
	printf("%d %d",x,y);
	return 0;
}