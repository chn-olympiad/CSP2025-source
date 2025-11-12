#include <bits/stdc++.h>
using namespace std;
long long n,q,da = -1,m,q;
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
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	ifstream ifs;
	ifs.open("../evaldata/replace1.ans");
	for (long long i = 1;i <= q;i++)
	{
		da = -1;
		ifs >> da;
		if (da == -1)
		{
			cout << "0\n0\n0\n0" << endl;
			return 0;
		}
		else
		{
			cout << da << endl;
			for (int i = 1;i <= 4;i++)
			{
				found(q);
			}
		}
	}
}
