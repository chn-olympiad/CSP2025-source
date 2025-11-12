#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int num,sum;
}a[105];

bool cmp(Node x,Node y)
{
	return x.sum > y.sum;
}

int n,m;
int main()
{
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++) 
	{
		a[i].num = i;
		cin >> a[i].sum;
	}
	
	int pos;
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n*m;i++)
	{
		if (a[i].num == 1)
		{
			pos = i;
			break;
		}
	}		
	
	for (int i = 1;i <= m;i++)
	{
		if (pos > n*(i-1) && pos <= n*i)
		{
			cout << i << " ";
			if (i % 2 == 1) cout << pos%n;
			else cout << n - pos%n;
			return 0;
		}
	}
}
