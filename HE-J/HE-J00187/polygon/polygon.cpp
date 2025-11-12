#include <iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int num,n,m,o;
	cin >> n >> m >> o;
	for (int i=0;n<=0;i++)
	{
		if (n+m<=0)
		{
			num++;
		}
	}
	cout << num;
	return 0;
}
