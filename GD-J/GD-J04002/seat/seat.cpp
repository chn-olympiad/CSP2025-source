#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[1005],xt,poss;
bool cmp(int x,int y)
{
	return x > y;
} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	xt = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	poss = 1;
	for(int i = 1;i <= n;i += 2)
	{
		for(int j = 1;j <= m;j++)
		{
			if(a[poss] == xt)
			{
				cout << i << " " << j;
				return 0;
			}
			poss++;
		}
		for(int j = m;j >= 1;j--)
		{
			if(a[poss] == xt)
			{
				cout << i + 1 << " " << j;
				return 0;
			}
			poss++;
		}
	}
	return 0;
}

