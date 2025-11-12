#include<bits/stdc++.h>
using namespace std;
void read(long long &n)
{
	n=0;
	char c=getchar();
	while(c>'9' or c<'0')c=getchar();
	while(c<='9' and c>='0')
	{
		n=n*10+c-'0';
		c=getchar();
	}
}
const int N=105;
struct node
{
	int idx;
	long long x;
};
bool cmp(node a,node b)
{
	return a.x>b.x;
}
node a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	read(n);
	read(m);
	for(int i=1;i<=n*m;i++)
	{
		read(a[i].x);
		a[i].idx=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].idx==1)
		{
			x=i;
		}
	}
	int zx=(x+n-1)/n;
	int zy=(zx%2?(x+n-1)%n+1:n-(x+n-1)%n);
	printf("%d %d\n",zx,zy);
	return 0;
}