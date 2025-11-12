#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int s[i];
	int maxI = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> i;
		if(s[i] >= '0' && s[i] <= '9')
		{
			if(s[i] > maxI)
			{
				maxI = s[i]; 
			}
		}
		cout << maxI;
	}
}
