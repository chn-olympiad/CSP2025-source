#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct aaa
{
	int v;
	bool c;
}a[100005];
int n,m;
bool cmp(aaa x,aaa y)
{
	return x.v > y.v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i].v;
		if(i == 1) a[i].c = 1;
	}
	sort(a + 1,a + n*m + 1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i].c)
		{
			cout << (i-1)/n+1 << " ";
			if(((i-1)/n+1) % 2 == 1)
			{
				int l = i%n;
				if(l == 0) l = n;
				cout << l << endl;
			}else
			{
				int l = i%n;
				if(l == 0) l = n;
				cout << (n-l+1) << endl;
			}
		}
	}
	return 0;
}
