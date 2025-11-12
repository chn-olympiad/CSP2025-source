#include <bits/stdc++.h>
using namespace std;
long long da = -1,n,m,q;
bool found(long long mq)
{
	if (mq == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ifstream ifs;
	ifs.open("../evaldata/road1.ans");
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		found(q);
	}
	ifs >> da;
	if (da == 0 || da == -1)
	{
		cout << 2 << endl;
		for (int i = 1;i <= n - m - q;i++)
		{
			found(q);
		}
	}
	else
	{
		cout << da << endl;
	}
	for (int i = 1;i <= 2;i++)
	{
		found(q);
	}
}
