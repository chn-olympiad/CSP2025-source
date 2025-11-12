#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int point;
	bool is_R;
}a[105];
bool cmp(node x,node y){return x.point>y.point;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].point);
	a[1].is_R=1;
	sort(a+1,a+1+n*m,cmp);
	int pos=0;
	for(int j=1;j<=m;j++)
	{
		if(j&1)
		{
			for(int i=1;i<=n;i++) if(a[++pos].is_R)
			{
				printf("%d %d\n",j,i);
				return 0;
			}
		}
		else
		{
			for(int i=n;i>=1;i--) if(a[++pos].is_R)
			{
				printf("%d %d\n",j,i);
				return 0;
			}
		}	
	}
	return 0;
}