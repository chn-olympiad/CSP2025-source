#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int a[1000010], tmp;
string s;
int main()
{
	cin >> s;
	for(int i = 0;s[i] != 0;i++)
	{
		if(s[i] >= 48&&s[i] <= 57)
		{
			tmp++;
			a[tmp] += s[i] - 48;
		}
	}
	for(int i = 1;i <= tmp;i++)
	{
		for(int j = 1;j <= i;j++)
		{
			if(a[j] < a[i])
				swap(a[j], a[i]);
		}
	}
	for(int i = 1;i <= tmp;i++)
		cout << a[i];
	return 0;
}
