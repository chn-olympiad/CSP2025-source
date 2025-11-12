#include <iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a , b,sum = 0,r = 0;
	cin >> a >> b;
	int s[a * b + 10] = {};
	for(int i = 1;i <= a * b;i ++)
	{
		cin >> s[i];
	}
	r = s[1];
	for(int i = 1;i <= a * b;i ++)
	{
		if(s[i] > r)
		{
			sum ++;
		}
	}
	int x  = 0;
	x += sum / a + 1;
	cout << x << " ";
	if(x % 2 == 0)
	{
		cout << b - sum % b;
		return 0;
	}
	else
	{
		cout << sum % b + 1;
		return 0;
	}
	return 0;
}
