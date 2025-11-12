#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n,m,rrank;

struct node
{
	int num,xiao = 0;
	
}peo[N];

bool cmp(node a,node b)
{
	return a.num > b.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	peo[1].xiao = 1;
	for (int i = 1;i <= n*m;i++)
	{
		cin>>peo[i].num;
	}
	sort(peo+1,peo+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++)
	{
		if (peo[i].xiao == 1)
		{
			rrank = i;
		}
	}
	bool idx = false;
	for (int i = 1;i <= m;i++)
	{
		if (i % 2)
		{
			idx = false;
		}
		else
		{
			idx = true;
		}
		if (rrank <= n)
		{
			if (idx)
			{
				cout<<i<<" "<<n - rrank + 1;
				break;
			}
			else
			{
				cout<<i<<" "<<rrank;
				break;
			}
		}
		rrank -= n;
	}
	return 0;
}
