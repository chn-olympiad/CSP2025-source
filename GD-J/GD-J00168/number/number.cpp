#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	
	int k = 0;
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 0;j < s.size();j++)
		{
			if((s[j] - '0') == i)
			{
				k *= 10;
				k += i;
				s[j] = ' ';
			}
		}
	}
	
	cout << k;
	
	return 0;
}
