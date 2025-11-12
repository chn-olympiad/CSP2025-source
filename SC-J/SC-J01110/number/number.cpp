#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005];
char c;
string x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	int k = 1;
	cin >> x;
	for(int i = 0;i < x.size();i ++)
	{
		if ('0' <= x[i] && x[i] <= '9')
		{
			a[k] = x[i] - '0';
			k ++;
		}
	}
	sort(a + 1,a + k);
	for(int j = k - 1;j >= 1;j --)
	{
		cout << a[j];
	}

	return 0;
}