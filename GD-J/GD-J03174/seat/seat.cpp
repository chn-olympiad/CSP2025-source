#include <cstdio>
#include <algorithm>
using namespace std;
const int N=201;
int n, m, x;
struct node
{
	int x, id;
} a[N];
bool cmp(node a, node b)
{
	return a.x==b.x?a.id>b.id:a.x>b.x;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int len=n*m;
	for(int i=1; i<=len; i++)
	{
		scanf("%d", &x);
		a[i]={x, i};
	}
	sort(a+1, a+len+1, cmp);
	int x=1, y=1;
	int b=1;
	for(int i=1; i<=len; i++)
	{
		if((y>n&&b>0)||(y<1&&b<0))
		{
			b=-b,x++;
			y=y>=n?n:1;
		}
		if(a[i].id==1) break;
		y+=b;
	}
	printf("%d %d", x, y);
	return 0;
} 
