#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;

int n , a[N] , sum;
int maxx = 0;
bool v[N];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin>>a[i];
		sum += a[i];
		maxx = max(maxx , a[i]);
	}
	if(n < 3)
	{
		cout<<0;
		return 0;
	}
	if(n == 3)
	{
		if(sum > 2 * maxx)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
		}
	}
}
