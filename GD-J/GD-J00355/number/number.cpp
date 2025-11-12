#include<iostream>
using namespace std;

int nums[10];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	while (true)
	{
		char c = getchar();
		if (c == '\n') break;
		
		if (c >= '0' && c <= '9')
			nums[c-'0']++;
	}
	
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= nums[i]; j++)
		{
			cout << i;
		}
	}
	
	return 0;
}
