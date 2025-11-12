#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1001];
	cin >> s;
	int j = 1;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] <= '9'&&s[i] >= '0')
		{
			a[j] = s[i] - '0';
			j++;
		}
	}
	j--;
	int num = j,max = -1,n;
	while(num != 0)
	{
		for(int i = 1;i <= j;i++)
		{
			if(a[i] > max&&a[i] != -1)
			{
				max = a[i];
				n = i;
			}
		}
		cout << max;
		a[n] = -1;
		num--;
		max = -1;
	}
	return 0;
}
