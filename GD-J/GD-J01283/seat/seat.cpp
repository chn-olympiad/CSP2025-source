#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int s[n*m],grade;
	for (int i = 0;i < n*m;i ++)
	{
		cin >> s[i];
	}
	grade = s[0];
	for (int i = 0;i < n*m;i ++)
	{
		s[i] *= -1;
	}
	sort(s,s+n*m);
	for (int i = 0;i < n*m;i ++)
	{
		s[i] *= -1;
	}
	int num;
	for (int i = 0;i < n*m;i ++)
	{
		if (s[i] == grade)
		{
			num = i+1;
		}
	}
	int c,r;
	if (num % n == 0)
	{
		c = num / n;
		if (c % 2 == 1)
		{
			r = n;
		}
		else
		{
			r = 1;
		}
	}
	else
	{
		c = num / n + 1;
		if (c % 2 == 1)
		{
			r = num % n;
		}
		else
		{
			r = n - num % n + 1;
		}
	}
	cout << c << " " << r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
