#include <bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum = 0;
	int a,b,c;
	cin >> a >> b;
	if (b == 0 && c <= 2)
	{
		cout << 1;
		return 0;
	}
	int ans[1],ansq[1];
	for(int i = 1;i <= a;i++)
	{
		cin >> ans[i];
	}
	for(int i = 2;i <= a;i++)
	{
		ansq[i]=ansq[i-1]=ans[i];//jy
	}
	for(int i = 1;i <= a;i++)
	{
		for(int i1 = i;i1 <= a;i1++)
		{
			int p = ansq[i]-ansq[i-1];
			p=p%b;
			{
				if (p==b)
				{
					sum++;
				}
			}
		}
	}
	cout <<sum;
	return 0;
}
