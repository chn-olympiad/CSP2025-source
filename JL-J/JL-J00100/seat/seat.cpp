//100
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int sum,id;
	bool operator < (const node x) const
	{	
		return sum>x.sum;
	}
}e[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&e[i].sum);
		e[i].id = i;
	}
	sort(e+1,e+n*m+1);
	int idx = 0;
	for(int i=1;i<=n*m;i++)
	{
		if(e[i].id==1) idx = i;
	}
	int qwq1 = idx/n;
	int qwq2 = idx%n;
	if(qwq2==0)
	{
		if(qwq1%2==0)
			printf("%d %d",qwq1,1);
		else
			printf("%d %d",qwq1,n);
	}
	else
	{
		if((qwq1+1)%2==0)
		{
			printf("%d %d",qwq1+1,n-qwq2+1);
		}
		else
		{
			printf("%d %d",qwq1+1,qwq2);
		}
	}
	return 0;

}