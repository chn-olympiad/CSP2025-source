#include <iostream>
#include <cstdio> 
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int a[15];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	for (int i = 0; i < int(s.size()); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[(int(s[i])-int('0'))]++;
		}
	}
	for (int n = 9; n >= 0; n--)
	{
		for (int i = 1; i <= a[n]; i++)
		{
			cout << n;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
