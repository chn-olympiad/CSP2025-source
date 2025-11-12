#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	int arr[10] = {0}; 
	cin >> str;
	for (int i=0;i<str.size();i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			int key = str[i] - '0';
			arr[key] += 1;
		}
	}
	
	for (int i=9;i>=0;i--)
	{
		while (arr[i] > 0)
		{
			cout << i;
			arr[i] -= 1;
		}
	}
	return 0;
} 
